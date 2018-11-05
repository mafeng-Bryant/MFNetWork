//
//  MFRequest.m
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFRequest.h"

@implementation MFRequest

-(instancetype)init
{
    self = [super init];
    _requestReformer = nil;
    _responseReformer = nil;
    _interceptor = nil;
    _injector = (id<MFRequestInjector>)self;
    if (_injector && [_injector respondsToSelector:@selector(initInjector:)]) {
        [_injector initInjector:self];
    }
    return self;
}

-(instancetype)initRequestUrl:(NSString*)url
                       method:(MFRequestMethodType)method
                   parameters:(id)parameters
                    loadCache:(BOOL)loadCache
                cacheDuration:(NSTimeInterval)cacheDuration
                 successBlock:(MFSuccessBlock)successBlock
                 failureBlock:(MFFailureBlock)failureBlock
{
    self = [super init];
    if (self) {
        _requestUrl = url;
        _method = method;
        _parameters = parameters;
        _loadCache = loadCache;
        _cacheDuration = cacheDuration;
        _successBlock = successBlock;
        _failureBlock = failureBlock;
    }
    return self;
}

- (NSDictionary *)responseHeaders
{
    return self.task.currentRequest.allHTTPHeaderFields;
}

- (NSInteger)responseStatusCode
{
    NSHTTPURLResponse * responses = (NSHTTPURLResponse *)self.task.response;
    return responses.statusCode;
}

-(NSString *)absoluteString
{
    return self.task.currentRequest.URL.absoluteString;
}

- (MFRequestType)requestType
{
    if (self.downloadFilePath) {
        return MFRequestTypeDownload;
    }else if (self.uploadUrl){
        return MFRequestTypeUpload;
    }
    return MFRequestTypeNormal;
}

- (NSString *)cacheDataFilePath
{
    if (self.requestType == MFRequestTypeNormal) {
        if (self.cacheDataFilePath.length>0) {
            return self.cacheDataFilePath;
        }
    }
    return @"";
}

- (NSString *)cacheDataInfoFilePath
{
    if (self.requestType == MFRequestTypeNormal) {
        if (self.cacheDataInfoFilePath.length>0) {
            return self.cacheDataInfoFilePath;
        }
    }
    return @"";
}

- (void)clearAllBlocks
{
    _successBlock  = nil;
    _failureBlock = nil;
    _uploadProgressBlock = nil;
    _uploadSuccessBlock = nil;
    _uploadFailedBlock = nil;
    _downloadSuccessBlock = nil;
    _downloadProgressBlock = nil;
    _downloadFailureBlock = nil;
}

@end
