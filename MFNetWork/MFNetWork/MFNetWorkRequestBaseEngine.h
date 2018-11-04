//
//  MFRequestBaseEngine.h
//  MFNetWork
//
//  Created by Mafeng-MacPro on 2018/11/4.
//  Copyright © 2018年 test. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MFRequest;

@interface MFNetWorkRequestBaseEngine : NSObject

- (void)addCustomHeaders;

- (void)requestDidSuccessWithRequest:(MFRequest*)request;

@end

