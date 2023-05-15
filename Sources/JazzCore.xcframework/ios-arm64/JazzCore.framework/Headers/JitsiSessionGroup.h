//
//  Created by Фролова Светлана Владимировна on 12.07.2024.
//  Copyright © 2024 Sberbank. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Cессионная группа
@interface JitsiSessionGroup : NSObject

/// Идентификатор сессионной группы
@property (nonatomic, strong, readonly) NSString *identifier;
/// Название группы
@property (nonatomic, strong, readonly) NSString *title;
/// Список участников
@property (nonatomic, strong, readonly) NSArray *participants;
/// Скрыта ли группа
@property (nonatomic, assign, readonly) BOOL isHidden;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithIdentifier:(NSString *)identifier
                             title:(NSString *)title
                      participants:(NSArray *)participants
                          isHidden:(BOOL)isHidden;

@end

NS_ASSUME_NONNULL_END
