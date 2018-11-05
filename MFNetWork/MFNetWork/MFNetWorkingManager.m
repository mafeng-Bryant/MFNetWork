//
//  MFNetWorkManager.m
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFNetWorkingManager.h"
#import "MFNetWorkingRequestEngine.h"
#import "MFNetWorkingRequestManager.h"
#import "MFNetWorkingRequestCommonHeader.h"

@interface MFNetWorkingManager()
@property (nonatomic,strong) MFNetWorkingRequestEngine* requestEngine;
@property (nonatomic,strong) MFNetWorkingRequestManager* requestManager;


@end

@implementation MFNetWorkingManager

+ (MFNetWorkingManager *)sharedInstance
{
    static MFNetWorkingManager *sharedManager = NULL;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedManager = [[MFNetWorkingManager alloc] init];
    });
    return sharedManager;
}

- (void)addCustomHeader:(NSDictionary *)header
{
    [[MFNetWorkingRequestCommonHeader sharedInstance] addCustomHeader:header];
}

- (NSDictionary *)customHeaders
{
    return [MFNetWorkingRequestCommonHeader sharedInstance].customHeaders;
}

- (void)sendGetRequest:(NSString *)url
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodGET
                         parameters:nil
                          loadCache:NO
                      cacheDuration:0
                            success:successBlock
                            failure:failureBlock];
    
}

- (void)sendGetRequest:(NSString *)url
            parameters:(id)parameters
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodGET
                         parameters:parameters
                          loadCache:NO
                      cacheDuration:0
                            success:successBlock
                            failure:failureBlock];
}

- (void)sendGetRequest:(NSString *)url
            parameters:(id)parameters
             loadCache:(BOOL)loadCache
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodGET
                         parameters:parameters
                          loadCache:loadCache
                      cacheDuration:0
                            success:successBlock
                            failure:failureBlock];
}

- (void)sendGetRequest:(NSString *)url
            parameters:(id)parameters
         cacheDuration:(NSTimeInterval)cacheDuration
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodGET
                         parameters:parameters
                          loadCache:NO
                      cacheDuration:cacheDuration
                            success:successBlock
                            failure:failureBlock];
}

- (void)sendGetRequest:(NSString *)url
            parameters:(id)parameters
             loadCache:(BOOL)loadCache
         cacheDuration:(NSTimeInterval)cacheDuration
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodGET
                         parameters:parameters
                          loadCache:loadCache
                      cacheDuration:cacheDuration
                            success:successBlock
                            failure:failureBlock];
}


- (void)sendPostRequest:(NSString *)url
             parameters:(id)parameters
                success:(MFSuccessBlock)successBlock
                failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodPOST
                         parameters:parameters
                          loadCache:NO
                      cacheDuration:0
                            success:successBlock
                            failure:failureBlock];
}



- (void)sendPostRequest:(NSString *)url
             parameters:(id)parameters
              loadCache:(BOOL)loadCache
                success:(MFSuccessBlock)successBlock
                failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodPOST
                         parameters:parameters
                          loadCache:loadCache
                      cacheDuration:0
                            success:successBlock
                            failure:failureBlock];
}

- (void)sendPostRequest:(NSString *)url
             parameters:(id)parameters
          cacheDuration:(NSTimeInterval)cacheDuration
                success:(MFSuccessBlock)successBlock
                failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodPOST
                         parameters:parameters
                          loadCache:NO
                      cacheDuration:cacheDuration
                            success:successBlock
                            failure:failureBlock];
}



- (void)sendPostRequest:(NSString *)url
             parameters:(id)parameters
              loadCache:(BOOL)loadCache
          cacheDuration:(NSTimeInterval)cacheDuration
                success:(MFSuccessBlock)successBlock
                failure:(MFFailureBlock)failureBlock
{
    [self.requestEngine sendRequest:url
                             method:MFRequestMethodPOST
                         parameters:parameters
                          loadCache:loadCache
                      cacheDuration:cacheDuration
                            success:successBlock
                            failure:failureBlock];
}

- (void)sendUploadImageRequest:(NSString *)url
                    parameters:(id)parameters
                         image:(UIImage *)image
                          name:(NSString *)name
                      mimeType:(NSString *)mimeType
                      progress:(MFUploadProgressBlock)uploadProgressBlock
                       success:(MFUploadSuccessBlock)uploadSuccessBlock
                       failure:(MFUploadFailureBlock)uploadFailureBlock
{
    
}

- (void)sendUploadImageRequest:(NSString *)url
                 ignoreBaseUrl:(BOOL)ignoreBaseUrl
                    parameters:(id)parameters
                         image:(UIImage *)image
                          name:(NSString *)name
                      mimeType:(NSString *)mimeType
                      progress:(MFUploadProgressBlock)uploadProgressBlock
                       success:(MFUploadSuccessBlock)uploadSuccessBlock
                       failure:(MFUploadFailureBlock)uploadFailureBlock
{
    
}

- (void)sendUploadImagesRequest:(NSString *)url
                     parameters:(id)parameters
                         images:(NSArray<UIImage *> *)images
                           name:(NSString *)name
                       mimeType:(NSString *)mimeType
                       progress:(MFUploadProgressBlock)uploadProgressBlock
                        success:(MFUploadSuccessBlock)uploadSuccessBlock
                        failure:(MFUploadFailureBlock)uploadFailureBlock
{
    
}

- (void)sendUploadImagesRequest:(NSString *)url
                  ignoreBaseUrl:(BOOL)ignoreBaseUrl
                     parameters:(id)parameters
                         images:(NSArray<UIImage *> *)images
                           name:(NSString *)name
                       mimeType:(NSString *)mimeType
                       progress:(MFUploadProgressBlock)uploadProgressBlock
                        success:(MFUploadSuccessBlock)uploadSuccessBlock
                        failure:(MFUploadFailureBlock)uploadFailureBlock
{
    
}

- (void)sendUploadImageRequest:(NSString *)url
                    parameters:(id)parameters
                         image:(UIImage *)image
                 compressRatio:(float)compressRatio
                          name:(NSString *)name
                      mimeType:(NSString *)mimeType
                      progress:(MFUploadProgressBlock)uploadProgressBlock
                       success:(MFUploadSuccessBlock)uploadSuccessBlock
                       failure:(MFUploadFailureBlock)uploadFailureBlock
{
    
}

- (void)sendUploadImageRequest:(NSString *)url
                 ignoreBaseUrl:(BOOL)ignoreBaseUrl
                    parameters:(id)parameters
                         image:(UIImage *)image
                 compressRatio:(float)compressRatio
                          name:(NSString *)name
                      mimeType:(NSString *)mimeType
                      progress:(MFUploadProgressBlock)uploadProgressBlock
                       success:(MFUploadSuccessBlock)uploadSuccessBlock
                       failure:(MFUploadFailureBlock)uploadFailureBlock
{
    
}

- (void)sendUploadImagesRequest:(NSString *)url
                     parameters:(id)parameters
                         images:(NSArray<UIImage *> *)images
                  compressRatio:(float)compressRatio
                           name:(NSString *)name
                       mimeType:(NSString *)mimeType
                       progress:(MFUploadProgressBlock)uploadProgressBlock
                        success:(MFUploadSuccessBlock)uploadSuccessBlock
                        failure:(MFUploadFailureBlock)uploadFailureBlock
{
    
}

- (void)sendUploadImagesRequest:(NSString *)url
                  ignoreBaseUrl:(BOOL)ignoreBaseUrl
                     parameters:(id)parameters
                         images:(NSArray<UIImage *> *)images
                  compressRatio:(float)compressRatio
                           name:(NSString *)name
                       mimeType:(NSString *)mimeType
                       progress:(MFUploadProgressBlock)uploadProgressBlock
                        success:(MFUploadSuccessBlock)uploadSuccessBlock
                        failure:(MFUploadFailureBlock)uploadFailureBlock
{
    
}

- (void)sendDownloadRequest:(NSString *)url
           downloadFilePath:(NSString *)downloadFilePath
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock
{
    
}

- (void)sendDownloadRequest:(NSString *)url
              ignoreBaseUrl:(BOOL)ignoreBaseUrl
           downloadFilePath:(NSString *)downloadFilePath
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock
{
    
}

- (void)sendDownloadRequest:(NSString *)url
           downloadFilePath:(NSString *)downloadFilePath
                  resumable:(BOOL)resumable
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock
{
    
}

- (void)sendDownloadRequest:(NSString *)url
              ignoreBaseUrl:(BOOL)ignoreBaseUrl
           downloadFilePath:(NSString *)downloadFilePath
                  resumable:(BOOL)resumable
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock
{
    
}

- (void)sendDownloadRequest:(NSString *)url
           downloadFilePath:(NSString *)downloadFilePath
          backgroundSupport:(BOOL)backgroundSupport
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock
{
    
}

- (void)sendDownloadRequest:(NSString *)url
              ignoreBaseUrl:(BOOL)ignoreBaseUrl
           downloadFilePath:(NSString *)downloadFilePath
          backgroundSupport:(BOOL)backgroundSupport
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock
{
    
}

- (void)sendDownloadRequest:(NSString *)url
           downloadFilePath:(NSString *)downloadFilePath
                  resumable:(BOOL)resumable
          backgroundSupport:(BOOL)backgroundSupport
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock
{
    
}

- (void)sendDownloadRequest:(NSString *)url
              ignoreBaseUrl:(BOOL)ignoreBaseUrl
           downloadFilePath:(NSString *)downloadFilePath
                  resumable:(BOOL)resumable
          backgroundSupport:(BOOL)backgroundSupport
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock
{
    
}

- (void)cancelAllCurrentRequests
{
    [self.requestManager cancelAllCurrentRequests];
}

#pragma mark set and get method

- (MFNetWorkingRequestEngine *)requestEngine
{    
    if (!_requestEngine) {
        _requestEngine = [[MFNetWorkingRequestEngine alloc] init];
    }
    return _requestEngine;
}

- (MFNetWorkingRequestManager *)requestManager
{
    if (!_requestManager) {
        _requestManager = [MFNetWorkingRequestManager sharedInstance];
    }
    return _requestManager;
}

-(void)dealloc
{
    [self cancelAllCurrentRequests];
}

@end
