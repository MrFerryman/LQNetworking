//
//  LQProtLifeCycleManager.h
//  LQNetworking
//
//  Created by w.q... on 2020/10/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// == Begin == 创建单例代码
#define DECLARE_SINGLETON_FOR_CLASS(classname, accessorname)    \
+ (classname *)accessorname;

#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname, accessorname) \
+ (classname *)accessorname                                     \
{                                                               \
static classname *accessorname = nil;                       \
static dispatch_once_t onceToken;                           \
dispatch_once(&onceToken, ^{                                \
accessorname = [[classname alloc] init];                \
});                                                         \
return accessorname;                                        \
}
// == End == 创建单例代码

@class LQNetworkBase;
@interface LQProtLifeCycleManager : NSObject

DECLARE_SINGLETON_FOR_CLASS(LQProtLifeCycleManager, sharedMgr)

@property (nonatomic, strong) NSMutableSet *workingProtocols;
- (void)lq_attachProtocolReference:(LQNetworkBase *)protocol;
- (void)lq_releaseProtocolReference:(LQNetworkBase **)protocol;

@end

NS_ASSUME_NONNULL_END
