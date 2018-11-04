//
//  MFNetWorkingHeader.h
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#ifndef MFNetWorkHeader_h
#define MFNetWorkHeader_h

#import <AFNetworking/AFNetworking.h>
#import "MFNetWorkingProtocol.h"

#ifdef DEBUG
#define MFLog(...) NSLog(@"%s line number:%d \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define MFLog(...)
#endif

//---------------------------------------normal request call block-----------------------------------------------------------------------//

typedef void(^MFSuccessBlock)(id responseObject);
typedef void(^MFFailureBlock)(NSURLSessionTask* task, NSError *error, NSInteger statusCode);

//---------------------------------------upload request call block-----------------------------------------------------------------------//

typedef void(^MFUploadSuccessBlock)(id responseObject);
typedef void(^MFUploadProgressBlock)(NSProgress *uploadProgress);
typedef void(^MFUploadFailureBlock)(NSURLSessionTask *task, NSError *error, NSInteger statusCode, NSArray<UIImage *>*uploadFailedImages);

//---------------------------------------download request call block-----------------------------------------------------------------------//

typedef void(^MFDownloadSuccessBlock)(id responseObject);
typedef void(^MFDownloadProgressBlock)(NSInteger receivedSize, NSInteger expectedSize, CGFloat progress);
typedef void(^MFDownloadFailureBlock)(NSURLSessionTask *task, NSError *error, NSString* resumableDataPath);


/**
 *  HTTP Request method
 */
typedef enum {
    MFRequestMethodGET,
    MFRequestMethodPOST,
    MFRequestMethodPUT,
    MFRequestMethodDELETE,
    MFRequestMethodHEADER
}MFRequestMethodType;

/**
 *  Request type
 */
typedef enum {
    MFRequestTypeNormal,
    MFRequestTypeUpload,
    MFRequestTypeDownload
}MFRequestType;

/**
 *  Manual operation by user (start,suspend,resume,cancel)
 */
typedef enum {
    MFDownloadManualOperationStart,
    MFDownloadManualOperationSuspend,
    MFDownloadManualOperationResume,
    MFDownloadManualOperationCancel
}MFDownloadManualOperationType;

typedef enum {
    MFRequestPrintLogTypeNone, //no request log will be printed
    MFRequestPrintLogTypeJSON, //request log will be printed with json format
    MFRequestPrintLogTypeNSObject //request log will be printed with NSObject format,e.g:NSArray,NSDictionary
}MFRequestPrintLogType;


static NSString *const MFRequestMethodGet     = @"GET";
static NSString *const MFRequestMethodPost    = @"POST";
static NSString *const MFRequestMethodHead    = @"HEAD";
static NSString *const MFRequestMethodPut     = @"PUT";
static NSString *const MFRequestMethodDelete  = @"DELETE";

#endif /* MFNetWorkHeader_h */
