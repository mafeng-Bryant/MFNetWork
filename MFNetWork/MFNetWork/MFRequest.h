//
//  MFRequest.h
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MFNetWorkHeader.h"
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
@property (nonatomic, readwrite, copy)   NSString *method;

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

//request type
- (MFRequestType)requestType;

//cache file path
- (NSString *)cacheDataFilePath;

//cache file info path
- (NSString *)cacheDataInfoFilePath;

//clear all blocks
- (void)clearAllBlocks;





@end

