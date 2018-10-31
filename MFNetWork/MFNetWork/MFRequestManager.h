//
//  MFRequestManager.h
//  MFNetWork
//
//  Created by patpat on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MFRequest;

//a dictionary to hold all current request models
typedef NSMutableDictionary<NSString*, MFRequest*> MFCurrentRequestModels;

@interface MFRequestManager : NSObject

/**
 *  单例模式
 *
 *  @return MFRequestManager实例
 */
+ (MFRequestManager*)sharedInstance;

/**
 *
 *  @return current models
 */
- (MFCurrentRequestModels*)currentRequest;

/**
 *
 *  This method is used to add a request model into current request models set
 */
- (void)addRequest:(MFRequest*)request;

/**
 *  This method is used to remove a request model from current request models set
 */
- (void)removeRequest:(MFRequest *)request;

/**
 *  This method is used to exchange a new request model with an old one
 */
- (void)changeRequestModel:(MFRequest *)request forKey:(NSString *)key;

/**
 *  This method is used to check if there is remaining curent request
 *
 *  @return if there is remaining requests
 */
- (BOOL)remainingCurrentRequests;

/**
 *  This method is used to calculate the count of current requests
 *
 *  @return the count of current requests
 */
- (NSInteger)currentRequestCount;

/**
 *  This method is used to log all current requests' information
 */
- (void)logAllCurrentRequests;


/**
 *  This method is used to cancel all current requests
 */
- (void)cancelAllCurrentRequests;

/**
 *  This method is used to cancel all current requests corresponding a reqeust url,
 *  no matter what the method is and parameters are
 *
 *  @param url              request url
 *
 */
- (void)cancelCurrentRequestWithUrl:(NSString *)url;

/**
 *  This method is used to cancel all current requests corresponding given reqeust urls,
 *  no matter what the method is and parameters are
 *
 *  @param urls              request url
 *
 */
- (void)cancelCurrentRequestWithUrls:(NSArray *)urls;

/**
 *  This method is used to cancel all current requests corresponding a specific reqeust url, method and parameters
 *
 *  @param url              request url
 *  @param method           request method
 *  @param parameters       parameters
 *
 */
- (void)cancelCurrentRequestWithUrl:(NSString *)url
                             method:(NSString *)method
                         parameters:(id)parameters;



@end

