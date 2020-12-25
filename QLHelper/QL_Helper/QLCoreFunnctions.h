//
//  QLCoreFunnctions.h
//  QLHelper
//
//  Created by 公智能 on 2020/12/25.
//  Copyright © 2020 com.lal. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <objc/runtime.h>

static inline void XMAfter(double time, void (^block)(void))
{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(time * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        if (block) {
            block();
        }
    });
}

static inline void XMDispatchMain(void (^block)(void))
{
    if ([NSThread isMainThread]) {
        if (block) {
            block();
        }
    } else {
        dispatch_async(dispatch_get_main_queue(), block);
    }
}

static inline void XMMainRunloopNext(void (^block)(void))
{
    dispatch_async(dispatch_get_main_queue(), block);
}

static inline void XMPostNotification(NSString *name, id object, NSDictionary *userInfo)
{
    if ([NSThread currentThread].isMainThread) {
        [[NSNotificationCenter defaultCenter] postNotificationName:name object:object userInfo:userInfo];
    } else {
        XMDispatchMain(^{
            [[NSNotificationCenter defaultCenter] postNotificationName:name object:object userInfo:userInfo];
        });
    }
}

static inline void XMAddObserve(id target, NSString *name, SEL selector, id object)
{
    if ([NSThread currentThread].isMainThread) {
        [[NSNotificationCenter defaultCenter] addObserver:target selector:selector name:name object:object];
    } else {
        XMDispatchMain(^{
            [[NSNotificationCenter defaultCenter] addObserver:target selector:selector name:name object:object];
        });
    }
}

static inline void XMRemoveObserve(id target, NSString *name, id object)
{
    if ([NSThread currentThread].isMainThread) {
        [[NSNotificationCenter defaultCenter] removeObserver:target name:name object:object];
    } else {
        XMDispatchMain(^{
            [[NSNotificationCenter defaultCenter] removeObserver:target name:name object:object];
        });
    }
}

static inline void XMRemoveAllObserve(id target)
{
    XMRemoveObserve(target, nil, nil);
}

static inline BOOL XMUserDefaultSave(id value, NSString *key)
{
    NSUserDefaults *userDefault = [NSUserDefaults standardUserDefaults];
    [userDefault setObject:value forKey:key];
    return  [userDefault synchronize];
}

static inline id XMUserDefaultGet(NSString *key)
{
    return [[NSUserDefaults standardUserDefaults] objectForKey:key];
}

static inline void XMUserDefaultRemove(NSString *key)
{
    [[NSUserDefaults standardUserDefaults] removeObjectForKey:key];
}

static inline int XMRandomNumber(int from, int to)
{
    return (int)(from + (arc4random() % (to - from + 1)));
}

static inline void XMMethodExchangedSwizzle(SEL origin, SEL swizzle, BOOL classMethod, Class cls)
{
    Method originalMethod = classMethod ? class_getClassMethod(cls, origin) : class_getInstanceMethod(cls, origin);
    Method swizzledMethod = classMethod ? class_getClassMethod(cls, swizzle) : class_getInstanceMethod(cls, swizzle);
    
    //    BOOL addSuccess = class_addMethod(cls, origin, method_getImplementation(swizzledMethod), method_getTypeEncoding(swizzledMethod));
    method_exchangeImplementations(originalMethod, swizzledMethod);
}
