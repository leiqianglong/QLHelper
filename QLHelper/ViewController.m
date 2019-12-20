//
//  ViewController.m
//  QLHelper
//
//  Created by LQL on 2019/12/20.
//  Copyright © 2019 com.lal. All rights reserved.
//

#import "ViewController.h"
#import "QDefines.h"
#import "QHelper.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
   
    
    
    NSLog(@"长版本号：%ld",IOS_VERSION_NUMBER);
    
    NSLog(@"版本号%f",IOS_VERSION);
    
    if ([QHelper isCurrentSystemAtLeastVersion:@"12.4.4"]) {
        NSLog(@"aaaa");
    }
    
    if ([QHelper isCurrentSystemLowerThanVersion:@"12.4.4"]) {
        NSLog(@"bbbb");
    }
    
    NSLog(@"%f",[UIScreen mainScreen].bounds.size.width);
    NSLog(@"%f",[UIScreen mainScreen].nativeBounds.size.width);
    
    NSLog(@"状态栏高度：%f",StatusBarHeight);

    //blcok 防止循环引用
    Q_WS(weakSelf); //弱引用self
    void(^block)(void) = ^{
        weakSelf.view.backgroundColor = [UIColor greenColor];
         Q_SS(strongSelf, weakSelf); //将weakself变成强引用
        strongSelf.view.backgroundColor = [UIColor whiteColor];
    };
    block();
    
    if (IS_IPHONE_X) {
        NSLog(@"111");
    }
    
}


@end
