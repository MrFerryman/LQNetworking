//
//  LQUploadBase.h
//  LQNetworking
//
//  Created by w.q... on 2020/10/19.
//

#import "LQNetworkBase.h"

NS_ASSUME_NONNULL_BEGIN

@protocol LQUploadProtDelegate <NSObject>

@optional
- (void)lq_uploadProtCallBack:(LQNetworkBase *)protocol
                uploadPrgress:(NSProgress *)uploadProgress;

@end
@interface LQUploadBase : LQNetworkBase

@property (nonatomic, weak) id <LQUploadProtDelegate> uploadDelegate;
@property (nonatomic, strong) NSProgress *uploadFileProgress;

- (void)      lq_startUploadWithDelegate:(id)delegate;
- (NSString *)lq_requestUploadUrl;
- (NSString *)lq_fileAbsolutePath;
- (void)      lq_onUploadFinish:(NSURLResponse *)response error:(NSError *)error;
- (BOOL)      lq_handleUploadFinishBySelf;

@end

NS_ASSUME_NONNULL_END
