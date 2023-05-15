//
//  Created by Бузырев Илья Леонидович on 18.03.2022.
//  Copyright © 2022 Sberbank. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Эндпоинт видеопотока участника конференции
@interface JitsiEndpoint : NSObject

/// Идентификатор участника конференции
@property (nonatomic, strong, readonly) NSString *identifier;
/// Расположен ли пользователь в режиме спикера на экране пользователя
@property (nonatomic, assign, readonly) BOOL isPrimary;
/// Закреплен ли участник
@property (nonatomic, assign, readonly) BOOL isPinned;
/// Находится ли участник на экране в режиме PiP
@property (nonatomic, assign, readonly) BOOL isThumbnail;
/// Демонстрирует ли участник экран
@property (nonatomic, assign, readonly) BOOL isSharingScreen;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithIdentifier:(NSString *)identifier
                         isPrimary:(BOOL)isPrimary
                          isPinned:(BOOL)isPinned
                       isThumbnail:(BOOL)isThumbnail
                   isSharingScreen:(BOOL)isSharingScreen;

@end

NS_ASSUME_NONNULL_END
