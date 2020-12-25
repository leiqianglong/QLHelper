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
#import "AppDelegate.h"

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

//-----------------------   UIColor     -----------------------------
/// UIColor 相关的宏，用于快速创建一个 UIColor 对象
#define HexRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
#define HexRGBAlpha(rgbValue,a) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:(a)]
#define UIColorMake(r, g, b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1]
#define UIColorMakeWithRGBA(r, g, b, a) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:a/1.0]


//弱引用 --  强引用
#pragma mark - Weak Strong dance
#define Q_WS(weakself) __weak typeof(self) weakself = self;
#define Q_SS(strongself, weakself) __strong typeof(weakself) strongself = weakself; \
if (strongself == nil) return;


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
#define IS_IPHONE_X \
({BOOL isPhoneX = NO;\
if (@available(iOS 11.0, *)) {\
isPhoneX = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isPhoneX);})
/*TabBar高度*/
#define kTabBarHeight (CGFloat)(IS_IPHONE_X?(49.0 + 34.0):(49.0))
/*状态栏和导航栏总高度*/
#define KNavBarHeight (CGFloat)(IS_IPHONE_X?(88.0):(64.0))

//------------------NTS ----- null to string----------------------------------
//将nil  null 等转成空字符串 防止崩溃
#define QNTS(string)\
({\
NSString *s=@"";\
if ([string isEqual:@"NULL"] || [string isKindOfClass:[NSNull class]] || [string isEqual:[NSNull null]] || [string isEqual:NULL] || [[string class] isSubclassOfClass:[NSNull class]] || string == nil || string == NULL || [string isKindOfClass:[NSNull class]] || [[string stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]] length]==0 || [string isEqualToString:@"<null>"] || [string isEqualToString:@"(null)"]) \
    s=@"";\
 else \
    s=(NSString *)string;\
  (s);\
})
//----------------------------------------------------
/** 设置HLLog可以打印出类名,方法名,行数 */
#ifdef DEBUG

#define DLog(format, ...) printf("class: <%p %s:(%d) > method: %s \n%s\n", self, [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __PRETTY_FUNCTION__, [[NSString stringWithFormat:(format), ##__VA_ARGS__] UTF8String] )
#else
#define DLog(...)
#endif
//----------------------------------------------------
//项目中默认的字体粗细
#define QSysFont(size) [UIFont systemFontOfSize:size]

#define QBFont(size) [UIFont boldSystemFontOfSize:size]
/// 中黑体
#define QMediumFont(size)  [UIFont fontWithName:@"PingFangSC-Medium" size:size]
/// 中粗体
#define QSemiboldFont(size)  [UIFont fontWithName:@"PingFangSC-Semibold" size:size]
/// 细体
#define QLightFont(size)  [UIFont fontWithName:@"PingFangSC-Light" size:size]
//----------------------------------------------------

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
