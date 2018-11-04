//
//  MFRequest.h
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MFNetWorkingHeader.h"
#import <UIKit/UIKit.h>

@interface MFRequest : NSObject

//unique identifer of a request
@property (nonatomic, copy) NSString* identifer;

//NSURLSessionTask
@property (nonatomic, strong) NSURLSessionTask* task;

//response
@property (nonatomic, readwrite, strong) NSURLResponse *response;

//requestUrl
@property (nonatomic, readwrite, copy)   NSString *requestUrl;

//request method
@property (nonatomic, readwrite)  MFRequestMethodType method;

//request header
@property (nonatomic, strong, readonly) NSDictionary *responseHeaders;

//request response code
@property (nonatomic, readonly)  NSInteger responseStatusCode;

//request absoluteString
@property (nonatomic, strong, readonly) NSString *absoluteString;

//request error
@property (nonatomic,readwrite) NSError* error;

//response responseObject
@property (nonatomic, readwrite, strong) id responseObject;

//request parameters
@property (nonatomic,strong) id parameters;

//load cache
@property (nonatomic,assign) BOOL loadCache;

//cache time
@property (nonatomic, readwrite, assign) NSTimeInterval cacheDuration;

//response data
@property (nonatomic, readwrite, strong) NSData *responseData;

//success block
@property (nonatomic, readwrite, copy)   MFSuccessBlock successBlock;

//failure block
@property (nonatomic, readwrite, copy)   MFFailureBlock failureBlock;

//upload url
@property (nonatomic, readwrite, copy)   NSString *uploadUrl;

//upload images(or image)array
@property (nonatomic, readwrite, copy)   NSArray<UIImage *> *uploadImages;

//image identifer
@property (nonatomic, readwrite, copy)   NSString *imagesIdentifer;

//mime type of upload file
@property (nonatomic, readwrite, copy)   NSString *mimeType;

//compress ratio of all upload images, default is 1(original)
@property (nonatomic, readwrite, assign) float imageCompressRatio;

//cache data file path
@property (nonatomic, readonly, copy)    NSString *cacheDataFilePath;

//cache data info file path(record info of corresponding cache data)
@property (nonatomic, readonly, copy)    NSString *cacheDataInfoFilePath;

//upload success block
@property (nonatomic, readwrite, copy)   MFUploadSuccessBlock uploadSuccessBlock;

//upload progress block
@property (nonatomic, readwrite, copy)   MFUploadProgressBlock uploadProgressBlock;

//upload faile block
@property (nonatomic, readwrite, copy)   MFUploadFailureBlock uploadFailedBlock;

//download file path
@property (nonatomic, readwrite, copy)   NSString *downloadFilePath;

//if support resumable download, default is YES
@property (nonatomic, readwrite, assign) BOOL resumableDownload;

//if support background download, default is NO
@property (nonatomic, readwrite, assign) BOOL backgroundDownloadSupport;

//stream used to save download data
@property (nonatomic, readwrite, strong) NSOutputStream *stream;

//total length of download file
@property (nonatomic, readwrite, assign) NSInteger totalLength;

//resume data file path
@property (nonatomic, readonly, copy)    NSString *resumeDataFilePath;

//resume data info file path
@property (nonatomic, readonly, copy)    NSString *resumeDataInfoFilePath;

//requst operation
@property (nonatomic, readwrite, assign) MFDownloadManualOperationType manualOperation;

//download success block
@property (nonatomic, readwrite, copy)   MFDownloadSuccessBlock downloadSuccessBlock;

//download progress block
@property (nonatomic, readwrite, copy)   MFDownloadProgressBlock downloadProgressBlock;

//download failure block
@property (nonatomic, readwrite, copy)   MFDownloadFailureBlock downloadFailureBlock;

//request reformer:对请求的数据统一做refrom处理，比如做签名，添加共用参数等
@property (nonatomic, weak) id<MFRequestReformer> requestReformer;

//response reformer:对返回的数据统一做refrom处理,比如对返回数据格式处理等
@property (nonatomic, weak) id<MFResponseReformer> responseReformer;

//拦截器:请求完成后调用，实现协议方法后，可以在方法里完成比如说对某一状态做处理。
@property (nonatomic, weak) id<MFResponseInterceptor> interceptor;

//注入器：初始化时，通过这个协议可以实现统一注入
@property (nonatomic, weak) id<MFRequestInjector> injector;

-(instancetype)initRequestUrl:(NSString*)url
                       method:(MFRequestMethodType)method
                   parameters:(id)parameters
                    loadCache:(BOOL)loadCache
                cacheDuration:(NSTimeInterval)cacheDuration
                 successBlock:(MFSuccessBlock)successBlock
                 failureBlock:(MFFailureBlock)failureBlock;


//request type
- (MFRequestType)requestType;

//cache file path
- (NSString *)cacheDataFilePath;

//cache file info path
- (NSString *)cacheDataInfoFilePath;

//clear all blocks
- (void)clearAllBlocks;

@end

