//
//  LQNetworkConfig.h
//  LQNetworking
//
//  Created by w.q... on 2020/10/19.
//

// common define
#define kMessage (@"errDesc")
#define kError   (@"errCode")
#define kData    (@"data")

// 返回码定义
#define kAPIResultCodeSuccess   @"0"       // 返回成功
#define kAPIResultCodeException @"-9999"   // 系统异常

// 超时时间类型
#define kLQTimeOutTypeNormal    @(10.0)
#define kLQTimeOutTypeOneMinute @(60.0)
#define kLQTimeOutTypeUnlimited @(90.0)

#define cLQTimeOutTypeGet ([[NSArray alloc] initWithObjects:\
kLQTimeOutTypeNormal,\
kLQTimeOutTypeOneMinute,\
kLQTimeOutTypeUnlimited, nil])

#define kLQTimeOutTypeNumber(type) ([cLQTimeOutTypeGet objectAtIndex:type])
#define kLQTimeOutTypeEnum(double) ([cLQTimeOutTypeGet indexOfObject:double])

/// 安全字符串
#define kSafeString(string) ((![string isKindOfClass:[NSString class]]) || \
                             ([string isKindOfClass:[NSNull class]]) || \
                             (!string) || \
                             (0 == string.length)  \
                            ? @"" : string)

typedef NS_ENUM(NSInteger, LQParameterType) {
    LQParameterTypeDictionary = 0,
    LQParameterTypeArray,
};

typedef NS_ENUM(NSInteger, LQNetworkResult) {
    LQNetworkResultNetworkUnavailable = 1,
    LQNetworkResultFailed,
    LQNetworkResultSuccess,
};

typedef NS_ENUM(NSInteger, LQRequestSerializerType) {
    LQRequestSerializerTypeHTTP = 0,
    LQRequestSerializerTypeJSON,
};

typedef NS_ENUM(NSInteger, LQTimeOutType) {
    LQTimeOutTypeNormal = 0,
    LQTimeOutTypeOneMinute,
    LQTimeOutTypeUnlimited,
};

typedef NS_ENUM(NSInteger, LQRequestMethod) {
    LQRequestMethodGET,
    LQRequestMethodPOST,
    LQRequestMethodDELETE,
};
