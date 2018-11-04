//
//  MFRequestCommonHeader.h
//  MFNetWork
//
//  Created by Mafeng-MacPro on 2018/11/4.
//  Copyright © 2018年 test. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MFNetWorkingRequestCommonHeader : NSObject

@property (nonatomic, readonly, strong) NSDictionary *customHeaders;

/**
 *  单例模式
 *
 *  @return MFRequestCommonHeader实例
 */
+ (MFNetWorkingRequestCommonHeader*)sharedInstance;

/**
 *
 *  @return commonHeaders实例
 */
+ (NSDictionary *)commonHeaders;

/**
 *
 *  @return commonParameters实例
 */
+ (NSDictionary *)commonParameters;

/**
 * 添加自定义头
 */
- (void)addCustomHeader:(NSDictionary*)header;

/**
 * 请求参数统一处理
 */
- (void)requestReformerWithHeaders:(id)headers
                        parameters:(id)parameters
                          finished:(void(^)(id newHeaders,id newParameters))result;




@end

