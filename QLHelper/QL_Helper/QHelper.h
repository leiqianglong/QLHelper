//
//  QHelper.h
//  QLHelper
//
//  Created by LQL on 2019/12/20.
//  Copyright © 2019 com.lal. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface QHelper : NSObject

+ (instancetype _Nonnull )sharedInstance;

@end

/*--------------------------------------------------------------------------
 获取  Images.xcassets 内的图片资源
 */
@interface QHelper (Bundle)
/// @param name 图片名
+ (nullable UIImage *)imageWithName:(NSString *_Nonnull)name;

@end

/*--------------------------------------------------------------------------
 获取系统版本
 */
@interface QHelper (SystemVersion)
+ (NSInteger)numbericOSVersion;
//比较两个系统版本号大小
+ (NSComparisonResult)compareSystemVersion:(nonnull NSString *)currentVersion toVersion:(nonnull NSString *)targetVersion;
//当前系统是否高于传入的版本信息
+ (BOOL)isCurrentSystemAtLeastVersion:(nonnull NSString *)targetVersion;
//当前系统是否低于传入的版本信息
+ (BOOL)isCurrentSystemLowerThanVersion:(nonnull NSString *)targetVersion;
@end


/*--------------------------------------------------------------------------
 听筒和扬声器
 */
@interface QHelper (AudioSession)

/**
 *  听筒和扬声器的切换
 *
 *  @param speaker   是否转为扬声器，NO则听筒
 *  @param temporary 决定使用kAudioSessionProperty_OverrideAudioRoute还是kAudioSessionProperty_OverrideCategoryDefaultToSpeaker，
 */
+ (void)redirectAudioRouteWithSpeaker:(BOOL)speaker temporary:(BOOL)temporary;

/**
 *  设置category
 *
 *  @param category 使用iOS7的category，iOS6的会自动适配
 */
+ (void)setAudioSessionCategory:(nullable NSString *)category;
@end

