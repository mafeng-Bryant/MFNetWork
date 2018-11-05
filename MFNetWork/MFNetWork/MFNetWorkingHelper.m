//
//  MFNetWorkingHelper.m
//  MFNetWork
//
//  Created by patpat on 2018/11/5.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFNetWorkingHelper.h"
#import "MFNetWorkingConfig.h"
#import "MFNetWorkingRequestCommonHeader.h"
#import "MFNetWorkingRequestManager.h"

@implementation MFNetWorkingHelper

+ (MFNetWorkingHelper *)sharedInstance
{
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

+ (void)init
{
    [MFNetWorkingHelper sharedInstance];
}

- (id)init {
    self = [super init];
    if (self) {
        [MFNetWorkingConfig initWithHost:@"https://www.baidu.com"];
        [MFNetWorkingConfig sharedInstance].printLogType = MFRequestPrintLogTypeJSON;
    }
    return self;
}

#pragma mark MFRequestReformer

- (void)requestReformerWithHeaders:(id)headers
                        parameters:(id)parameters
                          finished:(void(^)(id newHeaders,id newParameters))result
{
    //reformer parameters
    NSDictionary *commonParameters = [MFNetWorkingRequestCommonHeader commonHeaders];
    NSDictionary *requestParameters = parameters;
    NSMutableDictionary *allParameters = [NSMutableDictionary dictionaryWithDictionary:commonParameters];
    if ([requestParameters isKindOfClass:[NSDictionary class]]) {
        [allParameters addEntriesFromDictionary:requestParameters];
    }
    
    NSDictionary *finalParameters = @{@"p":[self toJsonString:allParameters]};
    //reformer headers
    NSDictionary *commonHeaders = [MFNetWorkingRequestCommonHeader commonParameters];
    NSMutableDictionary *finalHeaders = [NSMutableDictionary dictionaryWithDictionary:commonHeaders];
    //NSString *sign =  [PPSignatureGenerator generateSignatureWithParameters:allParameters];
    //finalHeaders[@"sign"] = sign;
    result(finalHeaders,finalParameters);
}

#pragma mark MFResponseReformer

- (void)responseReormer:(MFRequest *)request
{
    if (!request.error) {
        [request status];  //请求成功了生成业务相关的status
        if (request.status && !request.status.normal) { //在这里将NSError和PPStatus合并为一个error
            NSMutableDictionary *descriptionDict = [NSMutableDictionary dictionary];
            descriptionDict[@"NSLocalizedErrorSummaryKey"] = @"opps!.....";
            descriptionDict[NSLocalizedDescriptionKey] = request.status.localizedDescription;
            request.error = [NSError errorWithDomain:request.status.domain code:[request.status.code integerValue] userInfo:descriptionDict];
        }
    }else{
        //重新设置请求失败的error信息
        NSMutableDictionary *descriptionDict = [NSMutableDictionary dictionary];
        if (![MFNetWorkingRequestManager isConnected]) { //lost network
            descriptionDict[@"NSLocalizedErrorSummaryKey"]= @"network error";
            descriptionDict[NSLocalizedDescriptionKey] = @"no network connect!";
        }else{
            descriptionDict[@"NSLocalizedErrorSummaryKey"]= @"request error";
            descriptionDict[NSLocalizedDescriptionKey] = request.error.localizedDescription;
        }
        request.error = [NSError errorWithDomain:request.error.domain code:request.error.code userInfo:descriptionDict];
    }
}

#pragma mark MFResponseInterceptor

- (void)interceptResponse:(MFRequest *)request
{
    MFApiStatus* api_status = request.status;
    if (api_status&&[api_status.code isEqualToString:@"1001"]) { //token过期了
        api_status.localizedDescription = @"token has expired!";
        NSLog(@"please login");
     }
}

- (NSString *)toJsonString:(NSDictionary*)paramaters
{
    if ([NSJSONSerialization isValidJSONObject:paramaters]){
        NSError *error;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:paramaters options:0 error:&error];
        NSString *json =[[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        return json;
    }
    return nil;
}

@end
