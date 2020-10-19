//
//  LQDownloadBase.h
//  LQNetworking
//
//  Created by w.q... on 2020/10/19.
//

#import "LQNetworkBase.h"

NS_ASSUME_NONNULL_BEGIN

@protocol LQDownloadProtDelegate <NSObject>

@optional
- (void)lq_downloadProtCallBack:(LQNetworkBase *)protocol
               downloadProgress:(NSProgress *)downloadProgress;

@end
@interface LQDownloadBase : LQNetworkBase

@property (nonatomic, weak) id<LQDownloadProtDelegate> downloadDelegate;
@property (nonatomic, strong) NSProgress *downloadFileProgress;

- (void)      lq_startDownloadWithDelegate:(id)delegate;
- (NSString *)lq_requestDownLoadUrl;
- (NSString *)lq_fileAbsolutePath;
- (void)      lq_onDownloadFinish:(NSURLResponse *)response
                         filePath:(NSURL *)filePath
                            error:(NSError *)error;
- (BOOL)      lq_handleDownloadFinishBySelf;

@end

NS_ASSUME_NONNULL_END
