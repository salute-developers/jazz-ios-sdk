//
//  Created by Фролова Светлана Владимировна on 12.07.2024.
//  Copyright © 2024 Sberbank. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class JitsiSessionGroup;

/// Общая информация о сессионных группах
@interface JitsiSessionGroups : NSObject

/// Список сессионных групп
@property (nonatomic, strong, readonly) NSArray<JitsiSessionGroup *> *groups;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithGroups:(NSArray<JitsiSessionGroup *> *)groups;

@end

NS_ASSUME_NONNULL_END
