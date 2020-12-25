//
//  UILabel+Extension.h
//  西安e充网
//
//  Created by zcsy_ios on 2017/11/2.
//  Copyright © 2017年 中创三优（西安）IOS. All rights reserved.
//态获取Label高度

#import <UIKit/UIKit.h>

@interface UILabel (Extension)

- (CGFloat)getSpaceLabelHeight:(NSString *)str withWidh:(CGFloat)width font:(CGFloat)font;

/**
 *  改变行间距
 */
+ (void)changeLineSpaceForLabel:(UILabel *)label WithSpace:(float)space;

/**
 *  改变字间距
 */
+ (void)changeWordSpaceForLabel:(UILabel *)label WithSpace:(float)space;

/**
 *  改变行间距和字间距
 */
+ (void)changeSpaceForLabel:(UILabel *)label withLineSpace:(float)lineSpace WordSpace:(float)wordSpace;


@end
