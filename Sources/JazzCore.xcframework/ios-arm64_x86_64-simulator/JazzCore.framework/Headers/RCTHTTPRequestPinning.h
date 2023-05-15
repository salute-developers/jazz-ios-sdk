//
//  Created by Mihail Vyrko on 09.09.2022.
//  Copyright © 2022 Sberbank. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^PinningBlock)(NSURLSessionAuthChallengeDisposition, NSURLCredential * _Nullable);

/**
 * Используется для обертки над `RCTHTTPRequestHandler`
 * чтобы не выставлять зависимость на `React`
 */
@interface RCTHTTPRequestPinning : NSObject

+ (void)addCertificatePinning:(void (^)(NSURLAuthenticationChallenge *, PinningBlock))handleBlock;

@end

NS_ASSUME_NONNULL_END
