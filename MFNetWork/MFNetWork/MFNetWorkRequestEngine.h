//
//  MFNetWorkRequestEngine.h
//  MFNetWork
//
//  Created by Mafeng-MacPro on 2018/11/4.
//  Copyright © 2018年 test. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MFNetWorkRequestBaseEngine.h"
#import "MFNetWork.h"

@interface MFNetWorkRequestEngine : MFNetWorkRequestBaseEngine

/**
 *  This method offers the most number of parameters of a certain network request.
 *
 *  @param url                request url
 *  @param method             request method
 *  @param parameters         parameters
 *  @param loadCache          consider whether to load cache
 *  @param cacheDuration      consider whether to write cache
 *  @param successBlock       success callback
 *  @param failureBlock       failure callback
 *
 */
- (void)sendRequest:(NSString *)url
             method:(MFRequestMethodType)method
         parameters:(id)parameters
          loadCache:(BOOL)loadCache
      cacheDuration:(NSTimeInterval)cacheDuration
            success:(MFSuccessBlock)successBlock
            failure:(MFFailureBlock)failureBlock;


@end
