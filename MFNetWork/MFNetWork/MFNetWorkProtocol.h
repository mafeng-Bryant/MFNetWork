//
//  MFNetWorkProtocol.h
//  MFNetWork
//
//  Created by Mafeng-MacPro on 2018/10/31.
//  Copyright © 2018年 test. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MFRequest;

@protocol MFNetworkProtocol <NSObject>

@required

/**
 *  This method is used to deal with the request model when the corresponding request is finished
 *
 */
- (void)handleRequesFinished:(MFRequest *)requestModel;

/**
 *  This method is used to deal with the request model when the corresponding request is failure
 *
 */
- (void)handleRequesFailure:(MFRequest *)requestModel;



@end



