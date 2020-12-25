//
//  ViewController.m
//  QLHelper
//
//  Created by LQL on 2019/12/20.
//  Copyright © 2019 com.lal. All rights reserved.
//

#import "ViewController.h"
#import "UIButton+Badge.h"

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
    
    
    NSString *nullStr = nil;
    QLog(@"nullStr === %@",QNTS(nullStr));
    
    self.view.backgroundColor = HexRGB(0xf2f3f4);
    
    
    UIButton *btn = [[UIButton alloc]initWithFrame:CGRectMake(100, 100, 150, 50)];
    [btn setTitle:@"角标" forState:(UIControlStateNormal)];
    btn.backgroundColor = HexRGB(0x999999);
    [btn showBadgeAtButton];
    [btn setImage:UIImageMake(@"gouxuan") forState:(UIControlStateNormal)];
    [btn layoutButtonWithEdgeInsetsStyle:(MKButtonEdgeInsetsStyleRight) imageTitleSpace:10];
    [self.view addSubview:btn];
    
    XMAfter(2, ^{
        DLog(@"延迟了2s。。。。");
    });
    XMDispatchMain(^{
        DLog(@"回到主线程");
    });
}



@end
