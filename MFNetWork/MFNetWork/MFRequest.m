//
//  MFRequest.m
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFRequest.h"

@implementation MFRequest

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
