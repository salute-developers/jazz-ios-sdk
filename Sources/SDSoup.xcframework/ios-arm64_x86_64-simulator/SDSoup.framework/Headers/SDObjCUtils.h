//
//  Created by Геронин Егор Николаевич on 02.11.2024.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ObjC)
@interface SDObjCUtils : NSObject

NS_SWIFT_NAME(ErrorDomain)
extern NSString * const SDObjCErrorDomain;

+ (void)perform:(void(NS_NOESCAPE^)(void))block error:(NSError **)error __attribute__((swift_error(nonnull_error)));

@end

NS_ASSUME_NONNULL_END
