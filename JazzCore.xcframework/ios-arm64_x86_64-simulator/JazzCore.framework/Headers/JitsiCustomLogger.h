//
//  Created by Nikolay Rodionov on 10.09.2021.
//  Copyright © 2021 Sberbank. All rights reserved.
//

#ifndef JitsiCustomLogger_h
#define JitsiCustomLogger_h

@protocol JitsiCustomLogger
- (void)logInfo:(NSString * _Nonnull)msg;
- (void)logWarn:(NSString * _Nonnull)msg;
- (void)logDebug:(NSString * _Nonnull)msg;
- (void)logError:(NSString * _Nonnull)msg;
@end

#endif /* JitsiCustomLogger_h */
