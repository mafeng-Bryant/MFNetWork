//
//  MFNetWorkHeader.h
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#ifndef MFNetWorkHeader_h
#define MFNetWorkHeader_h

#import <AFNetworking/AFNetworking.h>

#ifdef DEBUG
#define MFLog(...) NSLog(@"%s line number:%d \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define MFLog(...)
#endif

/////////////////////////////////////////normal request call block/////////////////////////////////////////////////////////////////////////
typedef void(^MFSuccessBlock)(id responseObject);
typedef void(^MFFailureBlock)(NSURLSessionTask* task, NSError *error, NSInteger statusCode);

/////////////////////////////////////////upload request call block/////////////////////////////////////////////////////////////////////////
typedef void(^MFUploadSuccessBlock)(id responseObject);
typedef void(^MFUploadProgressBlock)(NSProgress *uploadProgress);
typedef void(^MFUploadFailureBlock)(NSURLSessionTask *task, NSError *error, NSInteger statusCode, NSArray<UIImage *>*uploadFailedImages);


/////////////////////////////////////////download request call block///////////////////////////////////////////////////////////////////////
typedef void(^MFDownloadSuccessBlock)(id responseObject);
typedef void(^MFDownloadProgressBlock)(NSInteger receivedSize, NSInteger expectedSize, CGFloat progress);
typedef void(^MFDownloadFailureBlock)(NSURLSessionTask *task, NSError *error, NSString* resumableDataPath);

/**
 *  HTTP Request method
 */
typedef NS_ENUM(NSInteger, MFRequestMethod) {
    MFRequestMethodGET = 10000,
    MFRequestMethodPOST,
    MFRequestMethodPUT,
    MFRequestMethodDELETE,
};

/**
 *  Request type
 */
typedef NS_ENUM(NSInteger, MFRequestType) {
    MFRequestTypeNormal = 20000,
    MFRequestTypeUpload,
    MFRequestTypeDownload
};

/**
 *  Manual operation by user (start,suspend,resume,cancel)
 */
typedef NS_ENUM(NSInteger, MFDownloadManualOperation) {
    MFDownloadManualOperationStart = 80000,
    MFDownloadManualOperationSuspend,
    MFDownloadManualOperationResume,
    MFDownloadManualOperationCancel,
};


#endif /* MFNetWorkHeader_h */
