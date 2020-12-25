//
//  UIImage+FJ.m
//  YiDian
//
//  Created by LQL on 2019/7/24.
//  Copyright © 2019 HeChuang. All rights reserved.
//

#import "UIImage+FJ.h"

@implementation UIImage (FJ)
//通过颜色来生成一个纯色图片
+(UIImage *)fromColor:(UIColor *)color{
    CGRect rect = CGRectMake(0, 0, SCREEN_WIDTH,IS_IPHONE_X ? 88 : 64);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage *img = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return img;
}
+(UIImage *)creatColor:(UIColor *)color size:(CGSize)size{
    CGRect rect = CGRectMake(0, 0, size.width,size.height);
    UIGraphicsBeginImageContext(rect.size);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, [color CGColor]);
    CGContextFillRect(context, rect);
    UIImage *img = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return img;
}
@end
