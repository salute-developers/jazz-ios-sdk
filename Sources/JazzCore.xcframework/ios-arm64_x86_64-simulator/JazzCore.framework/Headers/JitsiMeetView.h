/*
 * Copyright @ 2018-present 8x8, Inc.
 * Copyright @ 2017-2018 Atlassian Pty Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "JitsiMeetConferenceOptions.h"
#import "JitsiMeetViewDelegate.h"
#import "JitsiReaction.h"

#import <WebRTC/RTCLogging.h>

@class WebRTCModuleWrapper;
@class JitsiEndpointPayload;

@interface JitsiMeetView : UIView

@property (nonatomic, nullable, weak) id<JitsiMeetViewDelegate> delegate;

/**
 * Joins the conference specified by the given options. The gievn options will
 * be merged with the defaultConferenceOptions (if set) in JitsiMeet. If there
 * is an already active conference it will be automatically left prior to
 * joining the new one.
 */
- (void)join:(JitsiMeetConferenceOptions *_Nullable)options;
/**
 * Leaves the currently active conference.
 */
- (void)leave;
- (void)hangUp;
- (void)setAudioMuted:(BOOL)muted;
- (void)toggleScreenShare:(BOOL)enabled;
- (void)sendChatMessage:(NSString* _Nonnull)message withId:(NSString* _Nullable)identifier;
- (void)setVideoMuted:(BOOL)muted shouldChangeAudioMode:(BOOL)shouldChangeAudioMode;
- (void)switchCamera;
- (void)setHandRaised:(BOOL)raised;
- (void)setRoomDisplayName:(NSString* _Nullable)roomDisplayName;
- (void)setAudioDenoiserEnabled:(BOOL)enabled;
- (void)setAsrEnabled:(BOOL)enabled;
- (void)setDisplayName:(NSString* _Nonnull)name;
- (void)sendEmoji:(JitsiReaction)emoji;
- (void)requestRoomPermission:(NSString* _Nonnull)permission;
- (void)updateVideoStream:(JitsiEndpointPayload* _Nonnull)endpointPayload;
- (void)approveAccess:(NSString* _Nonnull)participantID;
- (void)denyAccess:(NSString* _Nonnull)participantID;

- (WebRTCModuleWrapper *_Nonnull) mediaStreamRetriever;

- (void)setWebRTCLogLevel:(RTCLoggingSeverity)level;
@end
