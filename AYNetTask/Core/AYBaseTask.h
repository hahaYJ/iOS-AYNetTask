//
//  AYBaseTask.h
//  AYNetTask
//
//  Created by hahaYJ on 2/27/16.
//  Copyright © 2016 杨捷. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AYDefine.h"

typedef void(^AYRequestCompletedBlock)(id data);
typedef void(^AYConfigurationRequestBlock)(id data);
typedef void(^AYUrlMapBlock)(NSString *origin);
typedef void(^AYPostParamsBlock)(NSDictionary *params);

@class AYBaseTask;
/**
 定义一套基本任务操作规则
 **/
@protocol AYNetAction

/** 发起get任务执行 **/
- (AYBaseTask * (^)(AYRequestCompletedBlock block))doGetTask;

/** 发起post任务执行 **/
- (AYBaseTask * (^)(AYRequestCompletedBlock block))doPostTask;

/** http 基本参数配置 **/
- (AYBaseTask * (^)(AYConfigurationRequestBlock block))configurationRequest;

/** url 重映射 **/
- (AYBaseTask * (^)(AYUrlMapBlock block))urlMap;

/** url 设置 **/
- (AYBaseTask * (^)(NSString *url))url;

/** post参数设置 **/
- (AYBaseTask * (^)(AYPostParamsBlock block))postParams;

@end

@interface AYBaseTask : NSObject <AYNetAction>

@end
