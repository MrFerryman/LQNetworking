//
//  LQNetworkBase.h
//  LQNetworking
//
//  Created by w.q... on 2020/10/19.
//

#import <Foundation/Foundation.h>
#import "LQNetworkConfig.h"

NS_ASSUME_NONNULL_BEGIN

@class LQNetworkBase, AFHTTPSessionManager;
@protocol LQNetworkProtDelegate <NSObject>

@required
- (void)lq_networkProtCallBack:(LQNetworkBase *)prot;

@end
@interface LQNetworkBase : NSObject

@property (nonatomic, weak) id <LQNetworkProtDelegate> delegate;
@property (nonatomic)           LQNetworkResult workResult;
@property (nonatomic, copy)           NSString *optCode;
@property (nonatomic, copy, nullable) NSString *optDesc;
@property (nonatomic, strong)                id responseObject;
@property (nonatomic, strong, nullable)      id optData;
@property (nonatomic, assign)   LQRequestMethod requestMethod;

+ (AFHTTPSessionManager *)lq_sharedHttpRequestManager;
+ (AFHTTPSessionManager *)lq_sharedHttpRequestHttpResponseManager;
+ (void)lq_serverURLDidChange;
- (void)lq_startWork;
- (void)lq_startWorkWithDelegate:(id)delegate;
- (void)lq_notifyDelegate;
- (void)lq_handleRequestSerializer;

/// 请求路径  ⚠️子类必须实现此方法
- (NSString *)lq_requestApiPath;

/// 配置请求参数  ⚠️子类必须实现此方法
- (NSMutableDictionary *)lq_requestParams;

/// 配置请求参数
- (NSArray *)lq_requestParamsArray;

///  响应数据 子类必须实现此方法⚠️
///  如果 - (BOOL)lq_handleResponseBySelf; 子类重写返回YES时 响应数据为原始数据
/// @param responseObject 响应数据
- (void)lq_onResponse:(id)responseObject;

/// 子类自定制请求参数配置
- (NSMutableDictionary *)lq_packageApiRequestingParams;

/// 子类可以决定是否自行处理响应的原始数据 默认为No 由基类统一处理
- (BOOL)lq_handleResponseBySelf;

/// 子类自定制公共参数
- (NSMutableDictionary *)lq_handleCommonParams;

/// 请求URL 子类可以自定制URL
- (NSString *)lq_handleURLString;

/// 请求BaseURL 子类可以自定制URL 必须指定baseURL type 为 LQBaseURLTypeCustom
- (NSString *)lq_requestApiBaseUrl;

/// 子类可以自定制响应message的key值 默认的key为 errDesc
/// @param responseObj 响应数据
- (NSString *)lq_getOptDesc:(id)responseObj;

/// 子类可以自定制响应code的key值 默认的key为 errCode
/// @param responseObj 响应数据
- (NSString *)lq_getOptCode:(id)responseObj;

/// 子类可以自定制响应code的key值 默认的key为 errCode
/// @param responseObj 响应数据
- (id)lq_getOptData:(id)responseObj;

/// 子类可以自定制base url 有默认值
- (NSString *)lq_generateBaseURL;

/// 子类可以自定制请求参数类型
- (LQParameterType)lq_handleParameterType;

/// 子类可以配置post请求序列化方式 默认为json
- (LQRequestSerializerType)lq_handleRequestSerializerType;

/// 子类可以配置超时时间类型 默认为60秒
- (LQTimeOutType)lq_handleTimeOutType;

@end

NS_ASSUME_NONNULL_END
