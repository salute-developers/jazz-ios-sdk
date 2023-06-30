Pod::Spec.new do |spec|
  spec.name         = 'JazzSDK'
  spec.version      = '23.6.1'
  spec.platform = :ios, '13.0'
  spec.license      = { :type => 'MIT', :file => 'LICENCE.MD' }
  spec.homepage     = 'https://developers.sber.ru/docs/ru/jazz/sdk/overview'
  spec.authors      = { 'Salute Devices LLC' => 'developers@sberdevices.ru' }
  spec.summary      = 'SDK позволяет встроить видеозвонки в любое приложение. Интерфейс звонков можно настроить под ваше приложение.'
  spec.source       = { :git => 'https://github.com/salute-developers/jazz-ios-sdk.git', tag: 'v23.6.1' }
  spec.ios.vendored_frameworks = 'Sources/JazzSDK.xcframework', 'Sources/LibSberCast.xcframework', 'Sources/JazzCore.xcframework', 'Sources/WebRTC.xcframework'
  
  spec.ios.resource = ['Sources/DevicesDesignSystemResources.bundle', 'Sources/JazzResources.bundle']
  
  spec.swift_version = '5.0'
  
end
