//
//  Created by Nikolay Rodionov on 02.12.2021.
//  Copyright © 2021 Sberbank. All rights reserved.
//

#ifndef WebRTCModuleWrapper_h
#define WebRTCModuleWrapper_h
#import <WebRTC/WebRTC.h>

@interface WebRTCModuleWrapper : NSObject
typedef void (^VideoStreamResult)(RTCVideoTrack *_Nullable);
typedef void (^AudioStreamResult)(RTCAudioTrack *_Nullable);
typedef void (^MediaAction)(void);

- (void) retrieveVideoTrack:(NSString *_Nonnull)identifier
                 completion:(VideoStreamResult _Nonnull)handler;
- (void) retrieveAudioTrack:(NSString *_Nonnull)identifier
                 completion:(AudioStreamResult _Nonnull)handler;

- (void) executeOnMediaQueue:(MediaAction _Nonnull)action;

@end

#endif /* WebRTCModuleWrapper_h */
