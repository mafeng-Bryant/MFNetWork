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
- (void)sendGetRequest:(NSString*)url
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
- (void)sendGetRequest:(NSString*)url
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
- (void)sendGetRequest:(NSString*)url
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
















@end

NS_ASSUME_NONNULL_END
