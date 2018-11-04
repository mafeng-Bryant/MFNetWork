//
//  MFNetWorkRequestEngine.m
//  MFNetWork
//
//  Created by Mafeng-MacPro on 2018/11/4.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFNetWorkRequestEngine.h"
#import "MFNetWorkConfig.h"
#import "AFNetworkActivityIndicatorManager.h"
#import "MFRequestCommonHeader.h"
#import "MFRequest.h"

@interface MFNetWorkRequestEngine()

@property (nonatomic,strong) AFHTTPSessionManager* sessionManager;

@end

@implementation MFNetWorkRequestEngine

-(instancetype)init
{
    self = [super init];
    if (self) {
        _sessionManager = [AFHTTPSessionManager manager];
        if ([MFNetWorkConfig sharedInstance].requestSerializer) {
            _sessionManager.requestSerializer = [MFNetWorkConfig sharedInstance].requestSerializer;
        }
        if ([MFNetWorkConfig sharedInstance].responseSerializer) {
            _sessionManager.responseSerializer = [MFNetWorkConfig sharedInstance].responseSerializer;
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
    _sessionManager.requestSerializer = [MFNetWorkConfig sharedInstance].requestSerializer;
    
    //response serializer type
    _sessionManager.responseSerializer  = [MFNetWorkConfig sharedInstance].responseSerializer;
    
    //set request timeout
    _sessionManager.requestSerializer.timeoutInterval = [MFNetWorkConfig sharedInstance].timeoutInterval;
    
    __block id param = nil;
    __block NSDictionary *headers = nil;
   //对请求的header和paramers参数做处理
    [[MFRequestCommonHeader sharedInstance] requestReformerWithHeaders:[MFRequestCommonHeader sharedInstance].customHeaders parameters:parameters finished:^(id newHeaders, id newParameters) {
        param = newParameters;
        headers = newHeaders;
    }];
    
    //add custom headers
    [self addCustomHeaders];
    
    if (loadCache) {
        
        
    }else {
        
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
    MFRequest* request = [[MFRequest alloc]init];
    request.requestUrl = url;
    request.method = method;
    request.parameters = parameters;
    request.loadCache = loadCache;
    request.cacheDuration = cacheDuration;
    
    
    
    
    
    
    
    


}

- (void)addCustomHeaders
{
    NSDictionary* headers = [MFRequestCommonHeader sharedInstance].customHeaders;
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
    NSString* host = [MFNetWorkConfig sharedInstance].host;
    NSURL* completeUrl = [[NSURL URLWithString:host] URLByAppendingPathComponent:url];
    return completeUrl.absoluteString;
}


@end
