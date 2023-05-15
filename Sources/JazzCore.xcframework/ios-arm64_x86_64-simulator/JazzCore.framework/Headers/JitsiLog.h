//
//  Created by Nikolay Rodionov on 10.09.2021.
//  Copyright © 2021 Sberbank. All rights reserved.
//

#ifndef JitsiLog_h
#define JitsiLog_h

#import "JitsiLogLevel.h"
#import "JitsiCustomLogger.h"

@interface JitsiLog : NSObject
+ (void)logInfo:(NSString*)msg, ...;
+ (void)logWarn:(NSString*)msg, ...;
+ (void)logDebug:(NSString*)msg, ...;
+ (void)logError:(NSString*)msg, ...;
+ (void)log:(JitsiLogLevel)level withFileName:(NSString *)fileName onLine:(NSInteger)fileLine message:(NSString*)msg;
+ (void)setup:(id<JitsiCustomLogger>)logger;
@end

#endif /* JitsiLog_h */
