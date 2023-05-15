//
//  Created by Вырко Михаил Анатольевич [B] on 21.09.2023.
//  Copyright © 2023 Sberbank. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Класс свизлит метод инициализации RTCCameraVideoCapturer
/// для установки флага isMultitaskingCameraAccessEnabled у AVCaptureSession
@interface CameraVideoCapturer : NSObject
+ (void)fixOrientation;
@end

NS_ASSUME_NONNULL_END
