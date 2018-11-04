//
//  MFRequestManager.m
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFNetWorkingRequestManager.h"
#import <pthread/pthread.h>
#import "objc/runtime.h"
#import "MFRequest.h"
#import "MFNetWorkingProtocol.h"

#define Lock() pthread_mutex_lock(&_lock)
#define Unlock() pthread_mutex_unlock(&_lock)

static char currentRequestKey;

@interface MFNetWorkingRequestManager()<MFNetWorkingProtocol>
{
    pthread_mutex_t _lock;
}

@end

@implementation MFNetWorkingRequestManager

+ (MFNetWorkingRequestManager *)sharedInstance {
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

-(instancetype)init
{
    self = [super init];
    if (self) {
        //lock
        pthread_mutex_init(&_lock, NULL);
    }
    return self;
}

- (MFCurrentRequestModels*)currentRequest
{
    MFCurrentRequestModels* currentTasks = objc_getAssociatedObject(self, &currentRequestKey);
    if (currentTasks) {
        return currentTasks;
    }
    currentTasks = [NSMutableDictionary dictionary];
    objc_setAssociatedObject(self, &currentRequestKey, currentTasks, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    return currentTasks;
}

- (void)addRequest:(MFRequest*)request
{
    Lock();
    [self.currentRequest setObject:request forKey:[NSString stringWithFormat:@"%ld",request.task.taskIdentifier]];
    Unlock();
}

- (void)removeRequest:(MFRequest *)request
{
    Lock();
    [self.currentRequest removeObjectForKey:[NSString stringWithFormat:@"%ld",request.task.taskIdentifier]];
    Unlock();
}

- (void)changeRequestModel:(MFRequest *)request forKey:(NSString *)key
{
    Lock();
    [self.currentRequest removeObjectForKey:key];
    [self.currentRequest setObject:request forKey:[NSString stringWithFormat:@"%ld",request.task.taskIdentifier]];
    Unlock();
}

- (BOOL)remainingCurrentRequests
{
    NSArray* allkeys = [self.currentRequest allKeys];
    if (allkeys.count>0) {
        MFLog(@"remaining current request");
        return YES;
    }
    MFLog(@"no remaining current request");
    return NO;
}

- (NSInteger)currentRequestCount
{
    if (![self remainingCurrentRequests]) {
        return 0;
    }
    NSArray* keys = [self.currentRequest allKeys];
    return keys.count;
}

- (void)logAllCurrentRequests
{
    if ([self remainingCurrentRequests]) {
       [self.currentRequest enumerateKeysAndObjectsUsingBlock:^(NSString * _Nonnull key, MFRequest * _Nonnull obj, BOOL * _Nonnull stop) {
           MFLog(@"===========Log Current rquest:\n %@",obj);
        }];
    }
}

- (void)cancelAllCurrentRequests
{
    if ([self remainingCurrentRequests]) {
        for (MFRequest* request in self.currentRequest.allValues) {
            if (request.requestType == MFRequestTypeNormal) {
                [request.task cancel];
                [self removeRequest:request];
            }
        }
    }
}

- (void)cancelCurrentRequestWithUrl:(NSString *)url
{
    if (![self remainingCurrentRequests]) {
        return;
    }
    
    NSMutableArray* cancelRequestModels = [NSMutableArray arrayWithCapacity:1];
    NSString* requestUrl = url;
    [self.currentRequest enumerateKeysAndObjectsUsingBlock:^(NSString * _Nonnull key, MFRequest * _Nonnull obj, BOOL * _Nonnull stop) {
        if ([obj.identifer containsString:requestUrl]) {
            [cancelRequestModels addObject:obj];
        }
    }];
    
    if (cancelRequestModels.count == 0) {
        MFLog(@"no request to be cancel");
    }else {
        
        [cancelRequestModels enumerateObjectsUsingBlock:^(MFRequest*  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            [obj.task cancel];
            [self removeRequest:obj];
        }];
    }
}

- (void)cancelCurrentRequestWithUrls:(NSArray *)urls
{
    if (urls.count ==0) {
        return;
    }
    
    if (![self remainingCurrentRequests]) {
        return;
    }
    
    [urls enumerateObjectsUsingBlock:^(NSString*  _Nonnull url, NSUInteger idx, BOOL * _Nonnull stop) {
        [self cancelCurrentRequestWithUrl:url];
    }];
}

- (void)cancelCurrentRequestWithUrl:(NSString *)url
                             method:(NSString *)method
                         parameters:(id)parameters
{
    
    
    
}


#pragma amrk MFNetworkProtocol

- (void)handleRequesFinished:(MFRequest *)requestModel
{
    [requestModel clearAllBlocks];
    [self removeRequest:requestModel];
}

- (void)handleRequesFailure:(MFRequest *)requestModel
{
    MFLog(@"retain request");
}

@end
