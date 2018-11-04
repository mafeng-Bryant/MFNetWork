//
//  MFRequestCommonHeader.m
//  MFNetWork
//
//  Created by Mafeng-MacPro on 2018/11/4.
//  Copyright © 2018年 test. All rights reserved.
//

#import "MFNetWorkingRequestCommonHeader.h"

@implementation MFNetWorkingRequestCommonHeader

+ (MFNetWorkingRequestCommonHeader *)sharedInstance
{
    static MFNetWorkingRequestCommonHeader *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

+ (NSDictionary *)commonHeaders;
{
    NSString *currencyCode = [[NSLocale currentLocale] objectForKey:NSLocaleCurrencyCode];
    return @{@"appversion":@"",
             @"buildversion":@"",
             @"platform":@"ios",
             @"screensize":@"",
             @"country":@"",
             @"language":@"",
             @"timezonename":@"",
             @"timezone":@"",
             @"deviceid":@"",
             @"currency":@"",
             @"countrycurrency":currencyCode};
}

+ (NSDictionary *)commonParameters
{
    NSMutableDictionary *parameters = [NSMutableDictionary dictionary];
    parameters[@"timestamp"] = @([[NSDate date]timeIntervalSince1970]);
    return parameters;
}

- (void)addCustomHeader:(NSDictionary *)header{
    
    if (![header isKindOfClass:[NSDictionary class]] ||([[header allKeys] count] == 0)) {
        return;
    }
    if (!_customHeaders) {
        _customHeaders = header;
        return;
    }
    //add custom header
    NSMutableDictionary *headers_info = [_customHeaders mutableCopy];
    [header enumerateKeysAndObjectsUsingBlock:^(NSString *key, NSString *value, BOOL * _Nonnull stop) {
        [headers_info setObject:value forKey:key];
    }];
    _customHeaders = [headers_info copy];
}

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
//    NSString *sign =  [PPSignatureGenerator generateSignatureWithParameters:allParameters];
//    finalHeaders[@"sign"] = sign;
    result(finalHeaders,finalParameters);
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
