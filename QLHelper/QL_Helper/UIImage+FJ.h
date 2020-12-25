//
//  UIImage+FJ.h
//  YiDian
//
//  Created by LQL on 2019/7/24.
//  Copyright © 2019 HeChuang. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (FJ)
//通过颜色来生成一个纯色图片
+(UIImage *)fromColor:(UIColor *)color;
+(UIImage *)creatColor:(UIColor *)color size:(CGSize)size;
@end

NS_ASSUME_NONNULL_END
