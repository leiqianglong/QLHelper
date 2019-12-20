//
//  QDefines.h
//  QLHelper
//
//  Created by LQL on 2019/12/20.
//  Copyright © 2019 com.lal. All rights reserved.
//

#ifndef QDefines_h
#define QDefines_h
#import "QHelper.h"


/// 操作系统版本号，只获取第二级的版本号，例如 10.3.1 只会得到 10.3
#define IOS_VERSION ([[[UIDevice currentDevice] systemVersion] doubleValue])
/// 数字形式的操作系统版本号，可直接用于大小比较；如 110205 代表 11.2.5 版本；根据 iOS 规范，版本号最多可能有3位
#define IOS_VERSION_NUMBER [QHelper numbericOSVersion]
/// 屏幕宽度，会根据横竖屏的变化而变化
#define SCREEN_WIDTH ([[UIScreen mainScreen] bounds].size.width)
/// 屏幕高度，会根据横竖屏的变化而变化
#define SCREEN_HEIGHT ([[UIScreen mainScreen] bounds].size.height)
/// 设备宽度，跟横竖屏无关
#define DEVICE_WIDTH MIN([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height)
/// 设备高度，跟横竖屏无关
#define DEVICE_HEIGHT MAX([[UIScreen mainScreen] bounds].size.width, [[UIScreen mainScreen] bounds].size.height)

/// 状态栏高度(来电等情况下，状态栏高度会发生变化，所以应该实时计算，iOS 13 起，来电等情况下状态栏高度不会改变)
#define StatusBarHeight (UIApplication.sharedApplication.statusBarHidden ? 0 : UIApplication.sharedApplication.statusBarFrame.size.height)

//设置图片
#define UIImageMake(img) [UIImage imageNamed:img]
//设置字体
#define UIFontMake(size) [UIFont systemFontOfSize:size]
#define UIFontBoldMake(size) [UIFont boldSystemFontOfSize:size]
#define UIFontBoldWithFont(_font) [UIFont boldSystemFontOfSize:_font.pointSize]
/// UIColor 相关的宏，用于快速创建一个 UIColor 对象
#define UIColorMake(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]
#define UIColorMakeWithRGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a/1.0]

//弱引用 --  强引用
#pragma mark - Weak Strong dance
#define Q_WS(weakself) __weak typeof(self) weakself = self;
#define Q_SS(strongself, weakself) __strong typeof(weakself) strongself = weakself; \
if (strongself == nil) return;

// Push 出下一个控制器
#define Q_PUSH_TO_CURRENT_NAVIGATION_VC(vc) \
UIViewController* curVC = [(AppDelegate *)[UIApplication sharedApplication].delegate currentViewController]; \
[curVC.navigationController pushViewController:(vc) animated:YES];


//判断相机是否可用
#define Q_CAMERA_IS_AVAILABLE ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera])
//图库是否可用
#define Q_PHOTO_IS_AVAILABLE ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypePhotoLibrary])

//获取字符串的多行size
#define Q_MULTILINE_TEXTSIZE(text, font, maxSize, mode) [text length] > 0 ? [text \
boundingRectWithSize:maxSize options:(NSStringDrawingUsesLineFragmentOrigin) \
attributes:@{NSFontAttributeName:font} context:nil].size : CGSizeZero
//获取字符串的单行size
#define Q_TEXTSIZE(text, font) [text length] > 0 ? [text \
sizeWithAttributes:@{NSFontAttributeName:font}] : CGSizeZero;Q

//是不是IPHONE_X系列
#define IS_IPHONE_X    ((SCREEN_WIDTH == 375.0f && SCREEN_HEIGHT == 812.0f) || (SCREEN_HEIGHT == 375.0f && SCREEN_WIDTH == 812.0f) || (SCREEN_WIDTH == 414.0f && SCREEN_HEIGHT == 896.0f) || (SCREEN_HEIGHT == 414.0f && SCREEN_WIDTH == 896.0f))

//使用6的尺寸标准
#define SCALE_WIDTH(w) ((SCREEN_WIDTH / 375) * w)
#define SCALE_HEIGHT(h) ((SCREEN_HEIGHT / 667) * h)

// UI设计作图标准是750*1334
#define ScaleHeight     SCREEN_HEIGHT / 667.0
#define ScaleWidth      SCREEN_WIDTH / 375.0
//Dbug Log
#ifdef DEBUG
#define QLog(fmt, ...) NSLog((fmt), ##__VA_ARGS__);
#else
#define QLog(...);
#endif
#endif /* QDefines_h */
