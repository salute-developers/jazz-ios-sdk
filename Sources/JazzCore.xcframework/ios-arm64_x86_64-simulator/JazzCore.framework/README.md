# Гайд по ReactNative JitsiMeetView

## Добавление событий ReactNative -> Swift

События из ReactNative изначально попададают в метод в ExternalAPI.m:
```
RCT_EXPORT_METHOD(sendEvent:(NSString *)name
                       data:(NSDictionary *)data
                      scope:(NSString *)scope)
```

Этот метод переводит полученное имя события (`name`) в camel case.
Например: SET_FATAL_ERROR -> setFatalError

Затем использует полученную строку чтобы найти и вызвать необходимый метод в JitsiMeetViewDelegate 

Чтобы добавить новое событие необходимо:
* Добавляем метод в протокол JitsiMeetViewDelegate
* Добавляем реализацию этого метода в `ConferenceStateImpl`
* Отправить событие из jitsi.js с помощью метода `_sendEvent`

## Добавление событий Swift -> ReactNative

События из Swift отправляются посредством объекта JitsiMeetView, который в свою очередь вызывает отправку события в объекте ExternalAPI.

Чтобы добавить новое событие нужно:
* Добавить событие в ExternalAPI.m (supportedEvents, constantsToExport)
* Добавить соотвествующие методы в ExternalAPI, JitsiMeetView, ConferenceInteractor
* подписаться на событие в jitsi.js в методе `_subscribeToNativeCode`

## Внесение изменений в JS код

Для того чтобы тестировать изменения в JS коде необходимо в таргете JazzCore в "Build Settings" изменить значение `USE_PREBUILT_JSBUNDLE` на `NO`.
После того как изменения протестированы нужно не забыть вернуть значение в `YES` 
После сборки копирование должно произойти автоматически, но можно это сделать в ручном режиме:
скопировать из derived data
.../DerivedData/Assistant-{хэш}/Build/Products/Debug-iphonesimulator/JazzCore.framework/main.jsbundle
в .../JazzCore/prebuilt_main.jsbundle.
После этого стоит проверить, что внесенные изменения действительно применились (clean проекта, очистить derived data, перезапустить) и делать ПР

Если есть неоходимость запуска metro bundler (например для горячей перезагрузки js), то необходимо в таргете JazzCore в "Build Settings" изменить значение `USE_METRO_BUNDLER` на `YES`
