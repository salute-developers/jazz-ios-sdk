/*
 * Copyright @ 2019-present 8x8, Inc.
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

#import "JitsiMeetUserInfo.h"
#import "JitsiMeetRoomInfo.h"


@interface JitsiMeetConferenceOptionsBuilder : NSObject

/**
 * Server where the conference should take place.
 */
@property (nonatomic, copy, nullable) NSURL *serverURL;
/**
 * Room name.
 */
@property (nonatomic, copy, nullable) NSString *room;
/**
 * Conference subject.
 */
@property (nonatomic, copy, nullable) NSString *subject;
/**
 * JWT token used for authentication.
 */
@property (nonatomic, copy, nullable) NSString *token;
/**
 * Авторизационный токен для звонков.
 */
@property (nonatomic, copy, nullable) NSString *authToken;
/**
 * Password used for authentication.
 */
@property (nonatomic, copy, nullable) NSString *password;

/**
 * Color scheme override, see:
 * https://github.com/jitsi/jitsi-meet/blob/master/react/features/base/color-scheme/defaultScheme.js
 */
@property (nonatomic, copy, nullable) NSDictionary *colorScheme;

/**
 * Feature flags. See: https://github.com/jitsi/jitsi-meet/blob/master/react/features/base/flags/constants.js
 */
@property (nonatomic, readonly, nonnull) NSDictionary *featureFlags;

/**
 * Set to YES to join the conference with audio / video muted or to start in audio
 * only mode respectively.
 */
@property (nonatomic) BOOL audioOnly;
@property (nonatomic) BOOL audioMuted;
@property (nonatomic) BOOL videoMuted;

/**
 * isCall - YES when P2P call, NO when conference
 */
@property (nonatomic) BOOL isCall;

/**
 * Set to YES to enable the welcome page. Typically SDK users won't need this enabled
 * since the host application decides which meeting to join.
 */
@property (nonatomic) BOOL welcomePageEnabled;

/**
 * Information about the local user. It will be used in absence of a token.
 */
@property (nonatomic, nullable) JitsiMeetUserInfo *userInfo;

@property (nonatomic, nullable) JitsiMeetRoomInfo *roomInfo;

- (void)setFeatureFlag:(NSString *_Nonnull)flag withBoolean:(BOOL)value;
- (void)setFeatureFlag:(NSString *_Nonnull)flag withValue:(id _Nonnull)value;

/**
 * CallKit call handle, to be used when implementing incoming calls.
 */
@property (nonatomic, copy, nullable) NSString *callHandle;

/**
 * CallKit call UUID, to be used when implementing incoming calls.
 */
@property (nonatomic, copy, nullable) NSUUID *callUUID;

/**
 * Name of peer in p2p calls
 */
@property (nonatomic, copy, nullable) NSString *peerName;

/**
 * Conference config for Jitsi
 */
@property (nonatomic, copy, nullable) NSDictionary *conferenceConfig;

/**
 * Conference options
 */
@property (nonatomic, copy, nullable) NSDictionary *options;

/**
 * Server URL
 */
@property (nonatomic, copy, nullable) NSString *stringUrl;

/**
 *  ConfId
 */
@property (nonatomic, copy, nullable) NSString *confId;

@end

@interface JitsiMeetConferenceOptions : NSObject

@property (nonatomic, copy, nullable, readonly) NSURL *serverURL;

@property (nonatomic, copy, nullable, readonly) NSString *room;
@property (nonatomic, copy, nullable, readonly) NSString *subject;
@property (nonatomic, copy, nullable, readonly) NSString *token;
@property (nonatomic, copy, nullable, readonly) NSString *authToken;
@property (nonatomic, copy, nullable, readonly) NSString *password;

@property (nonatomic, copy, nullable) NSDictionary *colorScheme;
@property (nonatomic, readonly, nonnull) NSDictionary *featureFlags;

@property (nonatomic, copy, nullable) NSDictionary *conferenceConfig;
@property (nonatomic, copy, nullable) NSDictionary *options;
@property (nonatomic, copy, nullable) NSString *stringUrl;
@property (nonatomic, copy, nullable) NSString *roomId;
@property (nonatomic, copy, nullable) NSString *confId;

@property (nonatomic, readonly) BOOL audioOnly;
@property (nonatomic, readonly) BOOL audioMuted;
@property (nonatomic, readonly) BOOL videoMuted;
@property (nonatomic, readonly) BOOL isCall;

@property (nonatomic, readonly) BOOL welcomePageEnabled;

@property (nonatomic, nullable) JitsiMeetUserInfo *userInfo;

@property (nonatomic, nullable) JitsiMeetRoomInfo *roomInfo;

@property (nonatomic, copy, nullable, readonly) NSString *callHandle;
@property (nonatomic, copy, nullable, readonly) NSUUID *callUUID;
@property (nonatomic, copy, nullable, readonly) NSString *peerName;

+ (instancetype _Nonnull)fromBuilder:(void (^_Nonnull)(JitsiMeetConferenceOptionsBuilder *_Nonnull))initBlock;
- (instancetype _Nonnull)init NS_UNAVAILABLE;

@end
