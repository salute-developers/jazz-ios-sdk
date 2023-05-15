#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SpenchAudioDenoise : NSObject

- (instancetype)initWithConfigFile:(NSString *)configFile
                          password:(NSString *)password
                          checksum:(NSString *)checksum;

- (uint32_t)getEngineThreads;
- (uint64_t)getModelSampleRate;
- (uint64_t)getModelInputFrameSize;

- (void)reloadConfig;
- (void)createContextWithInSampleRate:(uint32_t)inSampleRate
                        outSampleRate:(uint32_t)outSampleRate;
- (void)destroyContext;
- (void)processChunkWithPCM16Buffer:(AVAudioPCMBuffer *)inputBuffer
                        completion:(void (^)(AVAudioPCMBuffer * _Nullable outputBuffer))completion;
- (void)getFinalChunk:(void (^)(AVAudioPCMBuffer * _Nullable outputBuffer))completion;

@end

NS_ASSUME_NONNULL_END