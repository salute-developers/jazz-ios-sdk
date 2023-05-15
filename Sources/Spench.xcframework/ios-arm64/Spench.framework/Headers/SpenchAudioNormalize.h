#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SpenchAudioNormalize : NSObject

- (instancetype)initWithConfigFile:(NSString *)configFile
                          password:(NSString *)password
                          checksum:(NSString *)checksum;

- (void)processChunkWithPCM16Buffer:(AVAudioPCMBuffer *)inputBuffer
                        completion:(void (^)(AVAudioPCMBuffer * _Nullable outputBuffer))completion;
- (void)getFinalChunk:(void (^)(AVAudioPCMBuffer * _Nullable outputBuffer))completion;

@end

NS_ASSUME_NONNULL_END
