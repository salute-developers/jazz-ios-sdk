/*
 * Copyright @ 2017-present 8x8, Inc.
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

@protocol JitsiMeetViewDelegate <NSObject>

@optional

/**
 * Вызывается когда выполнено подключение по xmpp.
 *
 * Словарь 'data' содержит следующие ключи: 'time': время за которое было осуществлено подключение (в миллисекундах).
 */
- (void)xmppConnectionEstablished:(NSDictionary *)data;

/**
 * Вызывается когда выполнена установка ICE соединения.
 *
 * Словарь 'data' содержит следующие ключи: 'time': время за которое было установлено соединение (в миллисекундах).
 */
- (void)iceConnectionEstablished:(NSDictionary *)data;

/**
 * Вызывается когда выполнена установка медиа соединения.
 *
 * Словарь 'data' содержит следующие ключи: 'time': общее время подключения к комнате до момента установки медиа соединения (в миллисекундах).
 */
- (void)mediaConnectionEstablished:(NSDictionary *)data;

/**
 * Called when a conference was joined.
 *
 * The `data` dictionary contains a `url` key with the conference URL.
 */
- (void)conferenceJoined:(NSDictionary *)data;

/**
 * Called when the active conference ends, be it because of user choice or
 * because of a failure.
 *
 * The `data` dictionary contains an `error` key with the error and a `url` key
 * with the conference URL. If the conference finished gracefully no `error`
 * key will be present. The possible values for "error" are described here:
 * https://github.com/jitsi/lib-jitsi-meet/blob/master/JitsiConnectionErrors.js
 * https://github.com/jitsi/lib-jitsi-meet/blob/master/JitsiConferenceErrors.js
 */
- (void)conferenceTerminated:(NSDictionary *)data;

/**
 * Вызывается когда получено сообщение session-initiate
 *
 * Словарь 'data' содержит следующие ключи: 'time': время (timestamp) получения события.
 */
- (void)jingleSessionInitReceived:(NSDictionary *)data;

/**
 * Вызывается когда сформировано сообщение session-accept, непосредственно перед его отправкой
 *
 * Словарь 'data' содержит следующие ключи: 'time': время (timestamp) формирования session-accept.
 */
- (void)jingleSessionAcceptPrepared:(NSDictionary *)data;

/**
 * Called when a number of participants exceeds the limit.
 */
- (void)maxParticipantsNumberHasBeenReached:(NSDictionary *)data;

/**
 * Вызывается при подключении к конференции.
 *
 * Словарь 'data' содержит следующий ключ: 'id' - идентификатор jid комнаты конференции.
 */
- (void)setRoomId:(NSDictionary *)data;

/**
 * Called when a participant has joined the conference.
 *
 * The `data` dictionary contains a `participantId` key with the id of the participant that has joined.
 */
- (void)participantJoined:(NSDictionary *)data;

/**
 * Called when a participant has left the conference.
 *
 * The `data` dictionary contains a `participantId` key with the id of the participant that has left.
 */
- (void)participantLeft:(NSDictionary *)data;

/**
 * Called when audioMuted state changed.
 *
 * The `data` dictionary contains a `muted` key with state of the audioMuted for the localParticipant.
 */
- (void)audioMutedChanged:(NSDictionary *)data;

/**
 * Called when a participant toggled shared screen.
 *
 * The `data` dictionary contains a `participantId` key with the id of the participant  and a 'sharing' key with boolean value.
 */
- (void)screenShareToggled:(NSDictionary *)data;

/**
 * Called when a chat message is received.
 *
 * The `data` dictionary contains `message`, `senderId` and  `isPrivate` keys.
 */
- (void)chatMessageReceived:(NSDictionary *)data;

/**
 * Вызывается когда приходит статус сообщения.
 * Словарь `data` содержит следующие ключи: `id` и `status`.
 * В ключе `status` возможны следующие значения: `MESSAGE_IN_PROGRESS`, `MESSAGE_DELIVERED`, `MESSAGE_TIMEOUT` и `MESSAGE_FORBIDDEN`.
 */
- (void)chatMessageStatusReceived:(NSDictionary *)data;

/**
 * Called when videoMuted state changed.
 *
 * The `data` dictionary contains a `muted` key with state of the videoMuted for the localParticipant.
 */
- (void)videoMutedChanged:(NSDictionary *)data;

/**
 * Called on phone hashes receive.
 *
 * The `data` dictionary contains a key-value pairs: `participantId` of type `String` and `phoneHashes` of type `[String]`.
 */
- (void)phoneHashesReceived:(NSDictionary *)data;

/**
 * Called on JS application will start (event listeners are registered)
 *
 * The `data` is nil
 */
- (void)appWillMount:(NSDictionary *)data;

/**
 * Called on JS application unload
 *
 * The `data` is nil
 */
- (void)appWillUnmount:(NSDictionary *)data;

/**
 * Called on change of display name of any participant
 *
 * The `data` dictionary contains encoded display name and id of participant
 */
- (void)displayNameChanged:(NSDictionary *)data;

/**
 * Called on change of dominant speaker in conference
 *
 * The `data` dictionary contains encoded id of participant
 */
- (void)dominantSpeakerChanged:(NSDictionary *)data;

/**
 * Called on audio or video track removed from participant
 *
 * The `data` dictionary contains encoded participant id, media type and track info
 */
- (void)mediaTrackRemoved:(NSDictionary *)data;

/**
 * Called on audio or video track added to participant
 *
 * The `data` dictionary contains encoded participant id, media type and track info
 */
- (void)mediaTrackAdded:(NSDictionary *)data;

/**
 * Called when conference administrator mutes our microphone or camera
 *
 * The `data` dictionary contains encoded media  ['audio' | 'video']
 */
- (void)participantMutedUs:(NSDictionary *)data;

/**
 * Called when current participant is kicked out of conference
 *
 * The `data` dictionary contains encoded reason  ['call-rejected' | 'callEnded' | 'You have been kicked.']
 */
- (void)kickedOut:(NSDictionary *)data;

/**
 * Called on emoji reaction is received
 *
 * The `data` dictionary contains encoded participantFromId and value from JitsiReaction
 */
- (void)reactionReceived:(NSDictionary *)data;

/**
 * Called when somebody raise a hand
 *
 * The `data` dictionary contains encoded value and participantIdFrom
 */
- (void)handRaisedReceived:(NSDictionary *)data;

/**
 * Called when error is received
 * The 'data' dictionary containts encoded error and isNetworkFailure bool
 */
- (void)setFatalError:(NSDictionary *)data;

/**
 * Called when user changed role
 * The 'data' dictionary containts encoded error and isNetworkFailure bool
 */
- (void)userRoleChanged:(NSDictionary *)data;

 /**
  * Called when data channel is opened.
  * When number of remote recipients changed from 0 to 1
  */
- (void)dataChannelOpened:(NSDictionary *)data;

/**
 * Вызывается когда выставляются разрешения приватной комнаты.
 * Словарь 'data' содержит данные для декодирования 'RoomPolicy'.
 */
- (void)setRoomPolicy:(NSDictionary *)data;

/**
 * Вызывается когда выставляются ролевые права в комнате.
 * Словарь 'data' содержит данные для декодирования 'PrivateRoom.AllPermissions'.
 */
- (void)setRolePermissions:(NSDictionary *)data;

/**
 * Вызывается когда выставляются настройки приватной комнаты.
 * Словарь 'data' содержит данные для декодирования 'PrivateRoom.RoomSettings'.
 */
- (void)setRoomSettings:(NSDictionary *)data;

/**
 * Called when admin give user some permission for room policy.
 * The 'data' dictionary containts permission according one of the room policy.
 */
- (void)setUserGrantedPermission:(NSDictionary *)data;

/**
 * Called when participant is recording.
 * The 'data' dictionary containts encoded participantId and isRecording bool
 */
- (void)participantIsRecording:(NSDictionary *)data;

/**
 * Called when watermarks text changes.
 * The 'data' dictionary comes in ["text": " "] format
 */
- (void)watermarksTextChanged:(NSDictionary *)data;

/**
 * Вызывается когда локальный пользователь подключается к лобби.
 * Словарь 'data' содержит ключ 'moderators'.
 */
- (void)lobbyLocalUserJoined:(NSDictionary *)data;

/**
 * Вызывается когда удаленный (remote) пользователь подключается к лобби.
 * Словарь 'data' содержит следующие ключи: 'id', 'name' и 'role'.
 */
- (void)lobbyRemoteUserJoined:(NSDictionary *)data;

/**
 * Вызывается когда удаленный (remote) пользователь выходит из лобби.
 * Словарь 'data' содержит следующий ключ: 'id'.
 */
- (void)lobbyRemoteUserLeft:(NSDictionary *)data;

/**
 * Called when conference owner has granted access to conference to local user.
 * The 'data' dictionary is empty and can be ignored
 */
- (void)lobbyAccessGranted:(NSDictionary *)data;

/**
 * Called when conference owner has denied access to conference to local user.
 * The 'data' dictionary is empty and can be ignored
 */
- (void)lobbyAccessDenied:(NSDictionary *)data;

/**
 * Вызывается при получении оставшегося времени до завершения конференции
 *
 * Словарь `data` содержит поле remaining, хранящее продолжительность конференции (в секундах)
 */
- (void)conferenceDurationReceived:(NSDictionary *)data;

/**
 * Вызывается когда переключается состояние транскрибации.
 * Словарь 'data' приходит в следующем формате: ["isEnabled": "true"]
 */
- (void)asrStatusUpdated:(NSDictionary *)data;

/**
 * Вызывается при получении транскрибированного текста.
 *
 * Словарь 'data' содержит следующие ключи: 'id', 'text' и 'timestamp'.
 */
- (void)asrResult:(NSDictionary *)data;

/**
 * Вызывается при старте вебинара
 * Словарь 'data' приходит в следующем формате:
 * "broadcast": {
 *  "hls": [
 *      {"url": "https://jazz.sber.ru/stream/$(content-id)/hls/index.m3u8"},
 *      {"url": "https://jazz.sber.ru/stream/$(content-id)-no-encryption/hls/index.m3u8"}
 *  ],
 *  "dash": [
 *      {"url": "https://stream.jazz.sber.ru/my-awesome-webinar/dash/index.mpd"}
 *  ],
 *  "smoothStreamong": [
 *      {"url": "https://stream.jazz.sber.ru/my-awesome-webinar/ss/index.ss"}
 *  ]
 * }
 * "actualStartDate": "2022-10-03T12:42:14.803+0300"
 */
- (void)webinarStarted:(NSDictionary *)data;

/**
 * Вызывается при обновлении счетчика участников в случае если
 * пользователь не может посчитать количество участников
 * (например установлен запрет на просмотр других участников)
 *  { "count": 126, "viewersCount": 22 }
 */
- (void)participantCountUpdated:(NSDictionary *)data;

/**
 * Вызывается при обновлении информации о пользователе.
 *
 * Словарь 'data' содержит следующие ключи: 'id', 'displayName', 'role', 'isGuest', 'isBot', 'userId'.
 */
- (void)participantUpdated:(NSDictionary *)data;

/**
 * Вызывается когда пользователь переключает расшифровку речи.
 *
 * Словарь 'data' содержит следующие ключи: 'userId' и 'isOn'.
 */
- (void)asrUpdated:(NSDictionary *)data;

/**
 * Успешный старт записи, рассылается как подключенным участникам, так и новым, если запись еще не закончилось
 *
 * Словарь 'data' содержит следующий ключ: videoRecordOwnerId
 * videoRecordOwnerId: идентификатор участника-владельца видео записи (participantId)
 */
- (void)serverVideoRecordStarted:(NSDictionary *)data;

/**
 * Остановка записи видео, рассылается только подключенным участникам
 *
 * Словарь 'data' содержит следующие ключи: videoRecordOwnerId, reason
 * videoRecordOwnerId: идентификатор участника-владельца видео записи (participantId)
 * reason: durationLimit, memoryLimit, error(не присылается если участник сам выключил запись)
 */
- (void)serverVideoRecordStopped:(NSDictionary *)data;

/**
 * Неуспешный автостарт записи, рассылается только подключенным участникам
 *
 * Словарь 'data' содержит следующий ключ: error
 * error: hasNoPermission, storageSizeExceeded, internalError
 */
- (void)serverVideoRecordAutoStartError:(NSDictionary *)data;

/**
 * Организатор завершил встречу для всех
 */
- (void)callEnded:(NSDictionary *)data;

/**
 * Получение статистики по медиа соединению
 *
 * Словарь 'data' содержит ключи метрики
 */
- (void)mediaConnectionStatsReceived:(NSDictionary *)data;

/**
 * Получение статистики по ice кандидатам
 *
 * Словарь 'data' содержит следующие ключи: type, address, port, protocol
 */
- (void)iceCandidateReceived:(NSDictionary *)data;

/**
 * Получение события о том, что опрос начался
 *
 * Словарь 'data' содержит следующие ключи: type, address, port, protocol
 */
- (void)pollStarted:(NSDictionary *)data;

/**
 * Получение события о том, что голосование в опросе завершено
 *
 * Словарь 'data' содержит следующие ключи: type, address, port, protocol
 */
- (void)pollFinished:(NSDictionary *)data;

/**
 * Получение события о том, что результаты голосования в опросе показаны голосовавшим
 *
 * Словарь 'data' содержит следующие ключи: type, address, port, protocol
 */
- (void)pollResultsPublished:(NSDictionary *)data;

/**
 * Получение события о том, что обновились результаты голосования в опросе
 *
 * Словарь 'data' содержит следующие ключи: type, address, port, protocol
 */
- (void)pollResultsUpdated:(NSDictionary *)data;

/**
 * Получение события о том, что опрос завершен
 *
 * Словарь 'data' содержит следующие ключи: type, address, port, protocol
 */
- (void)pollClosed:(NSDictionary *)data;

/**
 * Получено событие о переходе в сессионную группу и выходе из нее
 * Словарь 'data' содержит следующие ключи: 'id'
 */
- (void)moveToRoom:(NSDictionary *)data;

/**
 * Получено событие о получении запроса на включение фичи со стороны
 * участника конференции
 */
- (void)permissionsRequestReceived:(NSDictionary *)data;

/**
 * Состояние сессионных групп и главного зала, при активной сессии
 *  Словарь data содержит следующие ключи: 'sessionGroups', 'mainGroup'
 */
- (void)groupsState:(NSDictionary *)data;

@end
