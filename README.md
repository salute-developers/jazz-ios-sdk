#  Интеграция Jazz SDK

## Требования к окружению

iOS: 14.x и выше; Swift: 5.6 и выше; Xcode: 13.3.1 и выше

## Подключение к проекту

1. Скопируйте содержимое архива в директорию с вашим проектом

2. Залинкуйте все .xcframework'и в нужному таргету в .xcodeproj. Полный список необходимых фреймфорков:

- CompanionCore.xcframework
- DevicesCore.xcframework
- DevicesDesignSystem.xcframework
- DevicesUI.xcframework
- JazzAPI.xcframework
- JazzBase.xcframework
- JazzCore.xcframework
- JazzImpl.xcframework
- JazzPushSupport.xcframework
- JazzSDK.xcframework
- JazzServices.xcframework
- JazzStrings.xcframework
- LibSberCast.xcframework
- SaluteDesignSystem.xcframework
- SDNavigation.xcframework
- Swing.xcframework
- WebRTC.xcframework

`Важно: В секцию Embeded Binaries нужно добавить только JazzCore, LibSbercast и WebRTC`

3. Скопируйте или сделайте символьные ссылки на следующие ресурсы из фреймворков:

- DevicesDesignSystem.xcframework/DevicesDesignSystemResources.bundle
- JazzImpl.xcframework/JazzResources.bundle

Далее добавляем все созданные ссылки на ресурсы в проект в нужный таргет и проверяем,
что они присутствует в секции **Copy Bundle Resources** во вкладке **Builds Phases**.

4. Обновите **Info.plist** вашего приложения:

Нужно предоставить описания для запроса доступа по ключам:

- **NSMicrophoneUsageDescription** - для доступа к микрофону
- **NSCameraUsageDescription** - для доступа к камере
- **NSBluetoothAlwaysUsageDescription** и **NSBluetoothPeripheralUsageDescription** - для доступа к bluetooth при бесшовном переводе конференции на одно из Sber-устройств

Кроме того для поиска устройств в локальной сети необходимо добавить:
```
<key>NSBonjourServices</key>
<array>
	<string>_staros._tcp</string>
</array>
```

## Использование SDK

Для доступа к функциям Jazz SDK нужно добавить `import JazzSDK` по месту использования
Перед использованием SDK (скорее всего на старте приложения) необходимо выполнить инициализацию, вызвав `Jazz.initialize`
После этого использовать все функции SDK можно через методы `JazzSession.shared`

## Подключение функционала демонстрации экрана

1. Создайте в своем проекте таргет типа **Broadcast Upload Extension** (галочку Include UI Extension следует снять)
2. Прилинкуйте к новому таргету фреймворки: JazzScreenShareImpl.xcframework, JazzSDKScreenShare.xcframework.
	`Важно: В секцию Embeded Binaries добавлять не нужно
3. Скопируйте или сделайте символьную ссылку на JazzScreenShareImpl/JazzScreenShareResources.bundle
4. Добавьте в основной таргет приложения и в новый таргет **Broadcast Upload Extension** app groups capability и укажите одинаковый идентификатор группы
5. Обновите **Info.plist** нового таргета и основного таргета приложения, чтобы в них содержался ключ `RTCAppGroupIdentifier` со значением равным идентификатору группы
6. Реализуйте `SampleHandler` чтобы он выглядел следующим образом:
```
import ReplayKit
import JazzSDKScreenShare

class SampleHandler: RPBroadcastSampleHandler {
    
    private lazy var screenShare = JazzScreenShare(onError: finishBroadcastWithError(_:))

    override func broadcastStarted(withSetupInfo setupInfo: [String : NSObject]?) {
        screenShare.broadcastStarted(withSetupInfo: setupInfo)
    }
    
    override func broadcastFinished() {
        screenShare.broadcastFinished()
    }
    
    override func processSampleBuffer(_ sampleBuffer: CMSampleBuffer, with sampleBufferType: RPSampleBufferType) {
        screenShare.processSampleBuffer(sampleBuffer, with: sampleBufferType)
    }
}
```
7. В основном таргете приложения при инициализации `JazzSDK` в `JazzSettings` укажите `screenShareExtensionIdentifier` равный `bundleId` вашего **Broadcast Upload Extension**

