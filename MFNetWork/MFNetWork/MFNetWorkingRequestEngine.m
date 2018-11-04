//
//  MFNetWorkRequestEngine.m
//  MFNetWork
//
//  Created by Mafeng-MacPro on 2018/11/4.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFNetWorkingRequestEngine.h"
#import "MFNetWorkingConfig.h"
#import "AFNetworkActivityIndicatorManager.h"
#import "MFNetWorkingRequestCommonHeader.h"
#import "MFRequest.h"
#import "MFNetWorkingRequestManager.h"
#import "MFNetWorkingLogger.h"

@interface MFNetWorkingRequestEngine()

@property (nonatomic,strong) AFHTTPSessionManager* sessionManager;

@end

@implementation MFNetWorkingRequestEngine

-(instancetype)init
{
    self = [super init];
    if (self) {
        _sessionManager = [AFHTTPSessionManager manager];
        if ([MFNetWorkingConfig sharedInstance].requestSerializer) {
            _sessionManager.requestSerializer = [MFNetWorkingConfig sharedInstance].requestSerializer;
        }
        if ([MFNetWorkingConfig sharedInstance].responseSerializer) {
            _sessionManager.responseSerializer = [MFNetWorkingConfig sharedInstance].responseSerializer;
        }
        AFSecurityPolicy *securityPolicy = [AFSecurityPolicy defaultPolicy];
        securityPolicy.allowInvalidCertificates = YES;
        securityPolicy.validatesDomainName = NO;
        _sessionManager.securityPolicy = securityPolicy;
        _sessionManager.responseSerializer.acceptableContentTypes = [self acceptableContentTypes];
        _sessionManager.operationQueue.maxConcurrentOperationCount = 4;
        [AFNetworkActivityIndicatorManager sharedManager].enabled = YES;
        [[AFNetworkReachabilityManager sharedManager]startMonitoring];
    }
    return self;
}

- (NSSet *)acceptableContentTypes
{
    NSMutableSet *acceptableContentTypes = [NSMutableSet setWithSet:_sessionManager.responseSerializer.acceptableContentTypes];
    [acceptableContentTypes addObject:@"text/html"];
    [acceptableContentTypes addObject:@"text/plain"];
    [acceptableContentTypes addObject:@"text/json"];
    [acceptableContentTypes addObject:@"text/xml"];
    [acceptableContentTypes addObject:@"text/javascript"];
    [acceptableContentTypes addObject:@"application/json"];
    return acceptableContentTypes;
}

- (void)sendRequest:(NSString *)url
             method:(MFRequestMethodType)method
         parameters:(id)parameters
          loadCache:(BOOL)loadCache
      cacheDuration:(NSTimeInterval)cacheDuration
            success:(MFSuccessBlock)successBlock
            failure:(MFFailureBlock)failureBlock
{
    if (url.length<=0) {
        return;
    }
    
    //request complete url
    NSString* completeUrl = [self buildReuestUrl:url];
    
    //request serializer type
    _sessionManager.requestSerializer = [MFNetWorkingConfig sharedInstance].requestSerializer;
    
    //response serializer type
    _sessionManager.responseSerializer  = [MFNetWorkingConfig sharedInstance].responseSerializer;
    
    //set request timeout
    _sessionManager.requestSerializer.timeoutInterval = [MFNetWorkingConfig sharedInstance].timeoutInterval;
    
    __block id param = nil;
    __block NSDictionary *headers = nil;
   //对请求的header和paramers参数做处理
    [[MFNetWorkingRequestCommonHeader sharedInstance] requestReformerWithHeaders:[MFNetWorkingRequestCommonHeader sharedInstance].customHeaders parameters:parameters finished:^(id newHeaders, id newParameters) {
        param = newParameters;
        headers = newHeaders;
    }];
    
    //add custom headers
    [self addCustomHeaders];
    
    if (loadCache) {
       
        
        
        
    }else  {
        
        [self starRequestWithCompleteUrl:completeUrl method:method parameters:param loadCache:loadCache cacheDuration:cacheDuration success:successBlock failure:failureBlock];
    }

}

- (void)starRequestWithCompleteUrl:(NSString*)url
                            method:(MFRequestMethodType)method
                        parameters:(id)parameters
                         loadCache:(BOOL)loadCache
                     cacheDuration:(NSTimeInterval)cacheDuration
                           success:(MFSuccessBlock)successBlock
                           failure:(MFFailureBlock)failureBlock
{
    
    //create request model
    MFRequest* request = [[MFRequest alloc]initRequestUrl:url method:method parameters:parameters loadCache:loadCache
                                            cacheDuration:cacheDuration successBlock:successBlock failureBlock:failureBlock];
    if (method == MFRequestMethodGET) {
        
        request.task = [_sessionManager GET:url parameters:parameters progress:^(NSProgress * _Nonnull downloadProgress) {
        } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
            [self handleRequestResult:task responseObject:responseObject error:nil];
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            [self handleRequestResult:task responseObject:nil error:error];
        }];
        
    }else if (method == MFRequestMethodPOST) {
        
        request.task = [_sessionManager POST:url parameters:parameters progress:^(NSProgress * _Nonnull uploadProgress) {
        } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
            [self handleRequestResult:task responseObject:responseObject error:nil];
        } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
            [self handleRequestResult:task responseObject:nil  error:error];
        }];
        
    }
    
    request.identifer = [NSString stringWithFormat:@"%lu", (unsigned long)[request.task taskIdentifier]];
    [MFNetWorkingLogger printWithRequest:NSStringFromClass([request class])
                                 methord:[self methordWithType:method]
                                     url:request.absoluteString
                                 headers:_sessionManager.requestSerializer.HTTPRequestHeaders
                                  params:parameters];
    //add request operation
    [[MFNetWorkingRequestManager sharedInstance] addRequest:request];
    [request.task resume];
}

- (void)handleRequestResult:(NSURLSessionTask *)operation
             responseObject:(id)responseObject
                      error:(NSError *)error
{
    NSString *key = [self requestHashKey:operation];
    MFRequest *request = [self getRequest:key];
    if (request) {
        request.error = error;
        if (!error) {
            request.responseObject = responseObject;
            if (request.successBlock) {
                request.successBlock(responseObject);
            }
        }else {
            if (request.failureBlock) {
                request.failureBlock(request.task, error, error.code);
            }
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            [self handleRequesFinished:request];
        });
    }
}

- (void)handleRequesFinished:(MFRequest*)request
{
    //print response
    [MFNetWorkingLogger printResponse:request error:request.error];

    //clear all blocks
    [request clearAllBlocks];
    
    //remove this request
    [[MFNetWorkingRequestManager sharedInstance] removeRequest:request];
}

- (MFRequest*)getRequest:(NSString*)key
{
    MFRequest* request = nil;
    NSDictionary* requestInfo = [MFNetWorkingRequestManager sharedInstance].currentRequest;
    if ([requestInfo objectForKey:key]) {
        request = requestInfo[key];
    }
    return request;
}

- (NSString *)requestHashKey:(NSURLSessionTask *)operation {
    NSString *key = [NSString stringWithFormat:@"%lu", (unsigned long)[operation taskIdentifier]];
    return key;
}

- (void)addCustomHeaders
{
    NSDictionary* headers = [MFNetWorkingRequestCommonHeader sharedInstance].customHeaders;
    if ([headers allKeys].count>0) {
        [headers enumerateKeysAndObjectsUsingBlock:^(id key, id value, BOOL *stop) {
            if ([key isKindOfClass:[NSString class]] && [value isKindOfClass:[NSString class]]) {
                [self->_sessionManager.requestSerializer setValue:key forHTTPHeaderField:value];
            }
        }];
    }
}

- (NSString*)buildReuestUrl:(NSString*)url
{
    if ([url hasPrefix:@"http"] || [url hasPrefix:@"https"]) {
        return url;
    }
    NSString* host = [MFNetWorkingConfig sharedInstance].host;
    NSURL* completeUrl = [[NSURL URLWithString:host] URLByAppendingPathComponent:url];
    return completeUrl.absoluteString;
}

#pragma mark Private methords

- (NSString *)methordWithType:(MFRequestMethodType)methord
{
    switch (methord) {
        case MFRequestMethodGET:
            return MFRequestMethodGet;
            break;
        case MFRequestMethodPOST:
            return MFRequestMethodPost;
            break;
        case MFRequestMethodPUT:
            return MFRequestMethodPut;
            break;
        case MFRequestMethodDELETE:
            return MFRequestMethodDelete;
            break;
        case MFRequestMethodHEADER:
            return MFRequestMethodHead;
            break;
        default:
            break;
    }
    return @"unknown";
}

@end
