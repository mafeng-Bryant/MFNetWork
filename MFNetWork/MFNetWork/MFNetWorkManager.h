//
//  MFNetWorkManager.h
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MFNetWork.h"

NS_ASSUME_NONNULL_BEGIN

@interface MFNetWorkManager : NSObject

/**
 *  单例模式
 *
 *  @return MFNetWorkManager实例
 */
+ (MFNetWorkManager *)sharedInstance;


/**
 *  This method is used to send GET request, not consider whether to write cache & not consider whether to load cache
 *
 *  @param url                 request url
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendGetRequest:(NSString *)url
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;

/**
 *  This method is used to send GET request, not consider whether to write cache & not consider whether to load cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendGetRequest:(NSString *)url
            parameters:(id)parameters
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;


/**
 *  This method is used to send GET request,
 consider whether to load cache but not consider whether to write cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param loadCache           consider whether to load cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendGetRequest:(NSString *)url
            parameters:(id)parameters
             loadCache:(BOOL)loadCache
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;

/**
 *  This method is used to send GET request,
 consider whether to write cache but not consider whether to load cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param cacheDuration       consider whether to write cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendGetRequest:(NSString *)url
            parameters:(id)parameters
         cacheDuration:(NSTimeInterval)cacheDuration
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;

/**
 *  This method is used to send GET request,
 consider whether to load cache and consider whether to write cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param loadCache           consider whether to load cache
 *  @param cacheDuration       consider whether to write cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendGetRequest:(NSString *)url
            parameters:(id)parameters
             loadCache:(BOOL)loadCache
         cacheDuration:(NSTimeInterval)cacheDuration
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;


/**
 *  This method is used to send POST request,
 not consider whether to write cache & not consider whether to load cache
 *
 *  @param url                request url
 *  @param parameters         parameters
 *  @param successBlock       success callback
 *  @param failureBlock       failure callback
 *
 */
- (void)sendPostRequest:(NSString *)url
             parameters:(id)parameters
                success:(MFSuccessBlock)successBlock
                failure:(MFFailureBlock)failureBlock;



/**
 *  This method is used to send POST request,
 consider whether to load cache but not consider whether to write cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param loadCache           consider whether to load cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendPostRequest:(NSString *)url
             parameters:(id)parameters
              loadCache:(BOOL)loadCache
                success:(MFSuccessBlock)successBlock
                failure:(MFFailureBlock)failureBlock;

/**
 *  This method is used to send POST request,
 consider whether to write cache but not consider whether to load cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param cacheDuration       consider whether to write cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendPostRequest:(NSString *)url
             parameters:(id)parameters
          cacheDuration:(NSTimeInterval)cacheDuration
                success:(MFSuccessBlock)successBlock
                failure:(MFFailureBlock)failureBlock;


/**
 *  This method is used to send POST request,
 consider whether to load cache and consider whether to write cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param loadCache           consider whether to load cache
 *  @param cacheDuration       consider whether to write cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendPostRequest:(NSString *)url
             parameters:(id)parameters
              loadCache:(BOOL)loadCache
          cacheDuration:(NSTimeInterval)cacheDuration
                success:(MFSuccessBlock)successBlock
                failure:(MFFailureBlock)failureBlock;


/**
 *  This method is used to send PUT request,
 not consider whether to write cache & not consider whether to load cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendPutRequest:(NSString *)url
            parameters:(id)parameters
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;


/**
 *  This method is used to send POST request,
 consider whether to load cache but not consider whether to write cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param loadCache           consider whether to load cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendPutRequest:(NSString *)url
            parameters:(id)parameters
             loadCache:(BOOL)loadCache
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;



/**
 *  This method is used to send POST request,
 consider whether to write cache but not consider whether to load cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param cacheDuration       consider whether to write cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendPutRequest:(NSString *)url
            parameters:(id)parameters
         cacheDuration:(NSTimeInterval)cacheDuration
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;


/**
 *  This method is used to send POST request,
 consider whether to load cache and consider whether to write cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param loadCache           consider whether to load cache
 *  @param cacheDuration       consider whether to write cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendPutRequest:(NSString *)url
            parameters:(id)parameters
             loadCache:(BOOL)loadCache
         cacheDuration:(NSTimeInterval)cacheDuration
               success:(MFSuccessBlock)successBlock
               failure:(MFFailureBlock)failureBlock;



#pragma mark- Request API using DELETE method

/**
 *  This method is used to send DELETE request,
 not consider whether to write cache & not consider whether to load cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendDeleteRequest:(NSString *)url
               parameters:(id)parameters
                  success:(MFSuccessBlock)successBlock
                  failure:(MFFailureBlock)failureBlock;



/**
 *  This method is used to send POST request,
 consider whether to load cache but not consider whether to write cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param loadCache           consider whether to load cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendDeleteRequest:(NSString *)url
               parameters:(id)parameters
                loadCache:(BOOL)loadCache
                  success:(MFSuccessBlock)successBlock
                  failure:(MFFailureBlock)failureBlock;



/**
 *  This method is used to send POST request,
 consider whether to write cache but not consider whether to load cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param cacheDuration       consider whether to write cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendDeleteRequest:(NSString *)url
               parameters:(id)parameters
            cacheDuration:(NSTimeInterval)cacheDuration
                  success:(MFSuccessBlock)successBlock
                  failure:(MFFailureBlock)failureBlock;


/**
 *  This method is used to send POST request,
 consider whether to load cache and consider whether to write cache
 *
 *  @param url                 request url
 *  @param parameters          parameters
 *  @param loadCache           consider whether to load cache
 *  @param cacheDuration       consider whether to write cache
 *  @param successBlock        success callback
 *  @param failureBlock        failure callback
 *
 */
- (void)sendDeleteRequest:(NSString *)url
               parameters:(id)parameters
                loadCache:(BOOL)loadCache
            cacheDuration:(NSTimeInterval)cacheDuration
                  success:(MFSuccessBlock)successBlock
                  failure:(MFFailureBlock)failureBlock;


/**
 *  This method is used to upload image
 *
 *  @param url                   request url
 *  @param parameters            parameters
 *  @param image                 UIImage object
 *  @param name                  file name
 *  @param mimeType              file type
 *  @param uploadProgressBlock   upload progress callback
 *  @param uploadSuccessBlock    uploadSuccess allback
 *  @param uploadFailureBlock    upload failure callback
 *
 */
- (void)sendUploadImageRequest:(NSString *)url
                    parameters:(id)parameters
                         image:(UIImage *)image
                          name:(NSString *)name
                      mimeType:(NSString *)mimeType
                      progress:(MFUploadProgressBlock _Nullable)uploadProgressBlock
                       success:(MFUploadSuccessBlock _Nullable)uploadSuccessBlock
                       failure:(MFUploadFailureBlock _Nullable)uploadFailureBlock;


/**
 *  This method is used to upload image
 *
 *  @param url                   request url
 *  @param ignoreBaseUrl         consider whether to ignore configured base url
 *  @param parameters            parameters
 *  @param image                 UIImage object
 *  @param name                  file name
 *  @param mimeType              file type
 *  @param uploadProgressBlock   upload progress callback
 *  @param uploadSuccessBlock    upload success callback
 *  @param uploadFailureBlock    upload failure callback
 *
 */
- (void)sendUploadImageRequest:(NSString *)url
                 ignoreBaseUrl:(BOOL)ignoreBaseUrl
                    parameters:(id)parameters
                         image:(UIImage *)image
                          name:(NSString *)name
                      mimeType:(NSString *)mimeType
                      progress:(MFUploadProgressBlock)uploadProgressBlock
                       success:(MFUploadSuccessBlock)uploadSuccessBlock
                       failure:(MFUploadFailureBlock)uploadFailureBlock;



/**
 *  This method is used to upload images(or only one image)
 *
 *  @param url                   request url
 *  @param parameters            parameters
 *  @param images                UIImage object array
 *  @param name                  file name
 *  @param mimeType              file type
 *  @param uploadProgressBlock   upload progress callback
 *  @param uploadSuccessBlock    upload success callback
 *  @param uploadFailureBlock    upload failure callback
 *
 */
- (void)sendUploadImagesRequest:(NSString *)url
                     parameters:(id)parameters
                         images:(NSArray<UIImage *> *)images
                           name:(NSString *)name
                       mimeType:(NSString *)mimeType
                       progress:(MFUploadProgressBlock)uploadProgressBlock
                        success:(MFUploadSuccessBlock)uploadSuccessBlock
                        failure:(MFUploadFailureBlock)uploadFailureBlock;



/**
 *  This method is used to upload images(or only one image)
 *
 *  @param url                   request url
 *  @param ignoreBaseUrl         consider whether to ignore configured base url
 *  @param parameters            parameters
 *  @param images                UIImage object array
 *  @param name                  file name
 *  @param mimeType              file type
 *  @param uploadProgressBlock   upload progress callback
 *  @param uploadSuccessBlock    upload success callback
 *  @param uploadFailureBlock    upload failure callback
 *
 */
- (void)sendUploadImagesRequest:(NSString *)url
                  ignoreBaseUrl:(BOOL)ignoreBaseUrl
                     parameters:(id)parameters
                         images:(NSArray<UIImage *> *)images
                           name:(NSString *)name
                       mimeType:(NSString *)mimeType
                       progress:(MFUploadProgressBlock)uploadProgressBlock
                        success:(MFUploadSuccessBlock)uploadSuccessBlock
                        failure:(MFUploadFailureBlock)uploadFailureBlock;



/**
 *  This method is used to upload image
 *
 *  @param url                   request url
 *  @param parameters            parameters
 *  @param image                 UIImage object
 *  @param compressRatio         compress ratio of images
 *  @param name                  file name
 *  @param mimeType              file type
 *  @param uploadProgressBlock   upload progress callback
 *  @param uploadSuccessBlock    upload success callback
 *  @param uploadFailureBlock    upload failure callback
 *
 */
- (void)sendUploadImageRequest:(NSString *)url
                    parameters:(id)parameters
                         image:(UIImage *)image
                 compressRatio:(float)compressRatio
                          name:(NSString *)name
                      mimeType:(NSString *)mimeType
                      progress:(MFUploadProgressBlock)uploadProgressBlock
                       success:(MFUploadSuccessBlock)uploadSuccessBlock
                       failure:(MFUploadFailureBlock)uploadFailureBlock;


/**
 *  This method is used to upload image
 *
 *  @param url                   request url
 *  @param ignoreBaseUrl         consider whether to ignore configured base url
 *  @param parameters            parameters
 *  @param image                 UIImage object
 *  @param compressRatio         compress ratio of images
 *  @param name                  file name
 *  @param mimeType              file type
 *  @param uploadProgressBlock   upload progress callback
 *  @param uploadSuccessBlock    upload success callback
 *  @param uploadFailureBlock    upload failure callback
 *
 */
- (void)sendUploadImageRequest:(NSString *)url
                 ignoreBaseUrl:(BOOL)ignoreBaseUrl
                    parameters:(id)parameters
                         image:(UIImage *)image
                 compressRatio:(float)compressRatio
                          name:(NSString *)name
                      mimeType:(NSString *)mimeType
                      progress:(MFUploadProgressBlock)uploadProgressBlock
                       success:(MFUploadSuccessBlock)uploadSuccessBlock
                       failure:(MFUploadFailureBlock)uploadFailureBlock;




/**
 *  This method is used to upload images(or only one image)
 *
 *  @param url                   request url
 *  @param parameters            parameters
 *  @param images                UIImage object array
 *  @param compressRatio         compress ratio of images
 *  @param name                  file name
 *  @param mimeType              file type
 *  @param uploadProgressBlock   upload progress callback
 *  @param uploadSuccessBlock    upload success callback
 *  @param uploadFailureBlock    upload failure callback
 *
 */
- (void)sendUploadImagesRequest:(NSString *)url
                     parameters:(id)parameters
                         images:(NSArray<UIImage *> *)images
                  compressRatio:(float)compressRatio
                           name:(NSString *)name
                       mimeType:(NSString *)mimeType
                       progress:(MFUploadProgressBlock)uploadProgressBlock
                        success:(MFUploadSuccessBlock)uploadSuccessBlock
                        failure:(MFUploadFailureBlock)uploadFailureBlock;




/**
 *
 *  @param url                   request url
 *  @param ignoreBaseUrl         consider whether to ignore configured base url
 *  @param parameters            parameters
 *  @param images                UIImage object array
 *  @param compressRatio         compress ratio of images
 *  @param name                  file name
 *  @param mimeType              file type
 *  @param uploadProgressBlock   upload progress callback
 *  @param uploadSuccessBlock    upload success callback
 *  @param uploadFailureBlock    upload failure callback
 *
 */
- (void)sendUploadImagesRequest:(NSString *)url
                  ignoreBaseUrl:(BOOL)ignoreBaseUrl
                     parameters:(id)parameters
                         images:(NSArray<UIImage *> *)images
                  compressRatio:(float)compressRatio
                           name:(NSString *)name
                       mimeType:(NSString *)mimeType
                       progress:(MFUploadProgressBlock)uploadProgressBlock
                        success:(MFUploadSuccessBlock)uploadSuccessBlock
                        failure:(MFUploadFailureBlock)uploadFailureBlock;






#pragma mark- Request API download files

/**
 *  These methods are used to download file
 *
 *  @param url                      request url
 *  @param downloadFilePath         target path of download file
 *  @param downloadProgressBlock    download progress callback
 *  @param downloadSuccessBlock     download success callback
 *  @param downloadFailureBlock     download failure callback
 *
 */
- (void)sendDownloadRequest:(NSString *)url
           downloadFilePath:(NSString *)downloadFilePath
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock;





/**
 *  These methods are used to download file
 *
 *  @param url                      request url
 *  @param ignoreBaseUrl            consider whether to ignore configured base url
 *  @param downloadFilePath         target path of download file
 *  @param downloadProgressBlock    download progress callback
 *  @param downloadSuccessBlock     download success callback
 *  @param downloadFailureBlock     download failure callback
 *
 */
- (void)sendDownloadRequest:(NSString *)url
              ignoreBaseUrl:(BOOL)ignoreBaseUrl
           downloadFilePath:(NSString *)downloadFilePath
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock;





/**
 *  These methods are used to download file
 *
 *  @param url                      request url
 *  @param downloadFilePath         target path of download file
 *  @param resumable                consider whether to save or load resumble data
 *  @param downloadProgressBlock    download progress callback
 *  @param downloadSuccessBlock     download success callback
 *  @param downloadFailureBlock     download failure callback
 *
 */
- (void)sendDownloadRequest:(NSString *)url
           downloadFilePath:(NSString *)downloadFilePath
                  resumable:(BOOL)resumable
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock;



/**
 *  These methods are used to download file
 *
 *  @param url                      request url
 *  @param ignoreBaseUrl            consider whether to ignore configured base url
 *  @param downloadFilePath         target path of download file
 *  @param resumable                consider whether to save or load resumble data
 *  @param downloadProgressBlock    download progress callback
 *  @param downloadSuccessBlock     download success callback
 *  @param downloadFailureBlock     download failure callback
 *
 */
- (void)sendDownloadRequest:(NSString *)url
              ignoreBaseUrl:(BOOL)ignoreBaseUrl
           downloadFilePath:(NSString *)downloadFilePath
                  resumable:(BOOL)resumable
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock;



/**
 *  These methods are used to download file
 *
 *  @param url                      request url
 *  @param downloadFilePath         target path of download file
 *  @param backgroundSupport        consider whether to support background downlaod
 *  @param downloadProgressBlock    download progress callback
 *  @param downloadSuccessBlock     download success callback
 *  @param downloadFailureBlock     download failure callback
 *
 */
- (void)sendDownloadRequest:(NSString *)url
           downloadFilePath:(NSString *)downloadFilePath
          backgroundSupport:(BOOL)backgroundSupport
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock;




/**
 *  These methods are used to download file
 *
 *  @param url                      request url
 *  @param ignoreBaseUrl            consider whether to ignore configured base url
 *  @param downloadFilePath         target path of download file
 *  @param backgroundSupport        consider whether to support background downlaod
 *  @param downloadProgressBlock    download progress callback
 *  @param downloadSuccessBlock     download success callback
 *  @param downloadFailureBlock     download failure callback
 *
 */
- (void)sendDownloadRequest:(NSString *)url
              ignoreBaseUrl:(BOOL)ignoreBaseUrl
           downloadFilePath:(NSString *)downloadFilePath
          backgroundSupport:(BOOL)backgroundSupport
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock;


/**
 *  These methods are used to download file
 *
 *  @param url                      request url
 *  @param downloadFilePath         target path of download file
 *  @param resumable                consider whether to save or load resumble data
 *  @param backgroundSupport        consider whether to support background downlaod
 *  @param downloadProgressBlock    download progress callback
 *  @param downloadSuccessBlock     download success callback
 *  @param downloadFailureBlock     download failure callback
 *
 */
- (void)sendDownloadRequest:(NSString *)url
           downloadFilePath:(NSString *)downloadFilePath
                  resumable:(BOOL)resumable
          backgroundSupport:(BOOL)backgroundSupport
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock;




/**
 *  These methods are used to download file
 *
 *  @param url                      request url
 *  @param ignoreBaseUrl            consider whether to ignore configured base url
 *  @param downloadFilePath         target path of download file
 *  @param resumable                consider whether to save or load resumble data
 *  @param backgroundSupport        consider whether to support background downlaod
 *  @param downloadProgressBlock    download progress callback
 *  @param downloadSuccessBlock     download success callback
 *  @param downloadFailureBlock     download failure callback
 *
 */
- (void)sendDownloadRequest:(NSString *)url
              ignoreBaseUrl:(BOOL)ignoreBaseUrl
           downloadFilePath:(NSString *)downloadFilePath
                  resumable:(BOOL)resumable
          backgroundSupport:(BOOL)backgroundSupport
                   progress:(MFDownloadProgressBlock)downloadProgressBlock
                    success:(MFDownloadSuccessBlock)downloadSuccessBlock
                    failure:(MFDownloadFailureBlock)downloadFailureBlock;



/**
 *  This method is used to cancel all current requests
 */
- (void)cancelAllCurrentRequests;









































































@end

NS_ASSUME_NONNULL_END
