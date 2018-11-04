//
//  MFRequest+RequestExtension.h
//  MFNetWork
//
//  Created by Mafeng-MacPro on 2018/11/4.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFRequest.h"

@interface MFRequest (RequestExtension)<MFRequestInjector>

@property (nonatomic, strong, readonly) id content; //kResponseKeyContent 内容

@end

