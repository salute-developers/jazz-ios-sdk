//
//  Created by Бузырев Илья Леонидович on 18.03.2022.
//  Copyright © 2022 Sberbank. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class JitsiEndpoint;

/// Общая информация об эндпоинтах, передаваемая для обработки на сервер
@interface JitsiEndpointPayload : NSObject

/// Эндпоинты видеопотоков участников конференции
@property (nonatomic, strong, readonly) NSArray<JitsiEndpoint *> *endpoints;
/// Максимальная высота разрешения для видеопотоков
@property (nonatomic, assign, readonly) NSInteger maxHeight;
/// Тип отображения видеопотоков (спикер/плитка)
@property (nonatomic, strong, readonly) NSString *viewType;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithEndpoints:(NSArray<JitsiEndpoint *> *)endpoints
                        maxHeight:(NSInteger)maxHeight
                         viewType:(NSString *)viewType;

@end

NS_ASSUME_NONNULL_END
