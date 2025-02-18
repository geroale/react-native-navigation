#import "RNNNavigationOptions.h"
#import "RNNReactComponentRegistry.h"

typedef void (^RNNReactViewReadyCompletionBlock)(void);

@interface RNNBasePresenter : NSObject

@property(nonatomic, weak, setter=bindViewController:) UIViewController *boundViewController;

@property(nonatomic, strong) NSString *boundComponentId;

@property(nonatomic, strong) RNNNavigationOptions *defaultOptions;

@property(nonatomic, strong) RNNReactComponentRegistry *componentRegistry;

- (instancetype)initWithDefaultOptions:(RNNNavigationOptions *)defaultOptions;

- (instancetype)initWithComponentRegistry:(RNNReactComponentRegistry *)componentRegistry
                           defaultOptions:(RNNNavigationOptions *)defaultOptions;

- (void)applyOptionsOnInit:(RNNNavigationOptions *)initialOptions;

- (void)applyOptionsOnViewDidLayoutSubviews:(RNNNavigationOptions *)options;

- (void)applyOptions:(RNNNavigationOptions *)options;

- (void)mergeOptions:(RNNNavigationOptions *)options
     resolvedOptions:(RNNNavigationOptions *)resolvedOptions;

- (void)renderComponents:(RNNNavigationOptions *)options
                 perform:(RNNReactViewReadyCompletionBlock)readyBlock;

- (void)viewDidLayoutSubviews;

- (void)componentWillAppear;

- (void)componentDidAppear;

- (void)componentDidDisappear;

- (UINavigationItem *)currentNavigationItem;

#if !TARGET_OS_TV
- (UIStatusBarStyle)getStatusBarStyle;

- (UIInterfaceOrientationMask)getOrientation;
#endif

- (BOOL)getStatusBarVisibility;

- (BOOL)hidesBottomBarWhenPushed;

- (BOOL)prefersHomeIndicatorAutoHidden;

@end
