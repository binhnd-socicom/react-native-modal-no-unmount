/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIKit.h>

#import <React/RCTInvalidating.h>
#import <React/RNModalHostViewManager.h>
#import <React/RCTView.h>

@class RCTBridge;
@class RNModalHostViewController;

@protocol RNModalHostViewInteractor;

@interface RNModalHostView : UIView <RCTInvalidating>

@property (nonatomic, copy) NSString *animationType;
@property (nonatomic, assign) UIModalPresentationStyle presentationStyle;
@property (nonatomic, assign, getter=isTransparent) BOOL transparent;

@property (nonatomic, copy) RCTDirectEventBlock onShow;

@property (nonatomic, copy) NSNumber *identifier;

@property (nonatomic, weak) id<RCTModalHostViewInteractor> delegate;

@property (nonatomic, copy) NSArray<NSString *> *supportedOrientations;
@property (nonatomic, copy) RCTDirectEventBlock onOrientationChange;

#if TARGET_OS_TV
@property (nonatomic, copy) RCTDirectEventBlock onRequestClose;
#endif

- (instancetype)initWithBridge:(RCTBridge *)bridge NS_DESIGNATED_INITIALIZER;

@end

@protocol RCTModalHostViewInteractor <NSObject>

- (void)presentModalHostView:(RNModalHostView *)modalHostView withViewController:(RNModalHostViewController *)viewController animated:(BOOL)animated;
- (void)dismissModalHostView:(RNModalHostView *)modalHostView withViewController:(RNModalHostViewController *)viewController animated:(BOOL)animated;

@end