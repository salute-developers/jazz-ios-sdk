Pod::Spec.new do |spec|
  spec.name         = 'JazzSDK'
  spec.version      = '23.4.1'
  spec.platform = :ios, '13.0'
  spec.license      = { :type => 'MIT', :file => 'LICENCE.MD' }
  spec.homepage     = 'https://developers.sber.ru/docs/ru/jazz/sdk/overview'
  spec.authors      = { 'Salute Devices LLC' => 'developers@sberdevices.ru' }
  spec.summary      = 'SDK позволяет встроить видеозвонки в любое приложение. Интерфейс звонков можно настроить под ваше приложение.'
  spec.source       = { :git => 'https://github.com/salute-developers/jazz-ios-sdk.git', tag: 'v23.4.1' }
  spec.ios.vendored_frameworks = 'Sources/JazzSDK.xcframework', 'Sources/JazzBase.xcframework', 'Sources/JazzAPI.xcframework', 'Sources/JazzServices.xcframework', 'Sources/LibSberCast.xcframework', 'Sources/DevicesUI.xcframework', 'Sources/JazzCore.xcframework', 'Sources/WebRTC.xcframework', 'Sources/DevicesCore.xcframework', 'Sources/DevicesDesignSystem.xcframework', 'Sources/SDNavigation.xcframework', 'Sources/JazzStrings.xcframework', 'Sources/SaluteDesignSystem.xcframework', 'Sources/JazzImpl.xcframework', 'Sources/Swing.xcframework', 'Sources/CompanionCore.xcframework', 'Sources/JazzSDKScreenShare.xcframework', 'Sources/JazzScreenShareImpl.xcframework'
  
  spec.swift_version = '5.0'
  
end
