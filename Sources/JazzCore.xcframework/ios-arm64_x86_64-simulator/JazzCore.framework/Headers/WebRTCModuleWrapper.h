//
//  Created by Nikolay Rodionov on 02.12.2021.
//  Copyright © 2021 Sberbank. All rights reserved.
//

#ifndef WebRTCModuleWrapper_h
#define WebRTCModuleWrapper_h
#import <WebRTC/WebRTC.h>

@interface WebRTCModuleWrapper : NSObject
typedef void (^MediaStreamResult)(RTCVideoTrack *_Nullable);
typedef void (^MediaAction)(void);

- (void) retrieveVideoTrack:(NSString *_Nonnull)reactTag
                 completion:(MediaStreamResult _Nonnull)handler;

- (void) executeOnMediaQueue:(MediaAction _Nonnull)action;

@end

#endif /* WebRTCModuleWrapper_h */
