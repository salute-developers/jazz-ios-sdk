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

## Известные ошибки при сборки и варианты решения

```
Can't find the 'node' binary to build the React Native bundle.  If you have a non-standard Node.js installation, select your project in Xcode, find  'Build Phases' - 'Bundle React Native code and images' and change NODE_BINARY to an  absolute path to your node executable. You can find it by invoking 'which node' in the terminal.
```
Выполнить команду 
ln -s $(which node) /usr/local/bin/node

```
Error: Cannot find module '@hapi/joi'
Require stack:
- /Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/tools/config/schema.js
- /Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/tools/config/readConfigFromDisk.js
- /Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/tools/config/index.js
- /Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/commands/install/install.js
- /Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/commands/index.js
- /Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/index.js
- /Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/react-native/cli.js
    at Function.Module._resolveFilename (internal/modules/cjs/loader.js:902:15)
    at Function.Module._load (internal/modules/cjs/loader.js:746:27)
    at Module.require (internal/modules/cjs/loader.js:974:19)
    at require (internal/modules/cjs/helpers.js:92:18)
    at t (/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/tools/config/schema.js:9:40)
    at Object.<anonymous> (/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/tools/config/schema.js:26:17)
    at Module._compile (internal/modules/cjs/loader.js:1085:14)
    at Object.Module._extensions..js (internal/modules/cjs/loader.js:1114:10)
    at Module.load (internal/modules/cjs/loader.js:950:32)
    at Function.Module._load (internal/modules/cjs/loader.js:790:14) {
  code: 'MODULE_NOT_FOUND',
  requireStack: [
    '/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/tools/config/schema.js',
    '/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/tools/config/readConfigFromDisk.js',
    '/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/tools/config/index.js',
    '/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/commands/install/install.js',
    '/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/commands/index.js',
    '/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/@react-native-community/cli/build/index.js',
    '/Users/out-vyrko-ma/Dev/assistant-sdk-ios/Submodules/JazzCore/node_modules/react-native/cli.js'
  ]
}
+ [[ false != true ]]
+ [[ ! -f /Users/out-vyrko-ma/Library/Developer/Xcode/DerivedData/SDWorkspace-gvauqoqdovyejidrjodcjcnsuikb/Build/Products/Debug-iphonesimulator/JazzCore.framework/main.jsbundle ]]
+ echo 'error: File /Users/out-vyrko-ma/Library/Developer/Xcode/DerivedData/SDWorkspace-gvauqoqdovyejidrjodcjcnsuikb/Build/Products/Debug-iphonesimulator/JazzCore.framework/main.jsbundle does not exist. This must be a bug with'
```

1) выполнить x setup_js
2) скопировать из логов билда и выполнить из папки Submodule/JazzCore

```
node --max_old_space_size=4096 {значение из логов}/Dev/main-project/Submodules/JazzCore/node_modules/react-native/cli.js bundle --entry-file index.ios.js --platform ios --dev false --reset-cache --bundle-output {значение из логов}/Library/Developer/Xcode/DerivedData/SDWorkspace-chzitypfvqzzirckdhuvizydmgli/Build/Products/Debug-iphonesimulator/JazzCore.framework/main.jsbundle --assets-dest {значение из логов}/Library/Developer/Xcode/DerivedData/SDWorkspace-chzitypfvqzzirckdhuvizydmgli/Build/Products/Debug-iphonesimulator/JazzCore.framework
```
