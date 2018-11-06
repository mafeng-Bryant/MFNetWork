//
//  MFNetWorkingRequestCommonParameterHeader.h
//  MFNetWork
//
//  Created by patpat on 2018/11/6.
//  Copyright © 2018年 test. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MFNetWorkingRequestCommonParameterHeader : NSObject

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
 *
 *  @return deviceModelName
 */
+ (NSString*)deviceModelName;


@end

