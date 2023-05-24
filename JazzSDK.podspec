Pod::Spec.new do |spec|
  spec.name         = 'JazzSDK'
  spec.version      = '23.4.1'
  spec.platform = :ios, '13.0'
  spec.license      = { :type => 'MIT', :file => 'LICENCE.MD' }
  spec.homepage     = 'https://developers.sber.ru/docs/ru/jazz/sdk/overview'
  spec.authors      = { 'Salute Devices LLC' => 'developers@sberdevices.ru' }
  spec.summary      = 'SDK позволяет встроить видеозвонки в любое приложение. Интерфейс звонков можно настроить под ваше приложение.'
  spec.source       = { :git => 'https://github.com/salute-developers/jazz-ios-sdk.git', tag: 'v.23.4.1' }
  spec.ios.vendored_frameworks = 'JazzSDK.xcframework', 'JazzBase.xcframework', 'JazzAPI.xcframework', 'JazzServices.xcframework', 'LibSberCast.xcframework', 'DevicesUI.xcframework', 'JazzCore.xcframework', 'WebRTC.xcframework', 'DevicesCore.xcframework', 'DevicesDesignSystem.xcframework', 'SDNavigation.xcframework', 'JazzStrings.xcframework', 'SaluteDesignSystem.xcframework', 'JazzImpl.xcframework', 'Swing.xcframework', 'CompanionCore.xcframework', 'JazzSDKScreenShare.xcframework', 'JazzScreenShareImpl.xcframework'
  
  spec.swift_version = '5.0'
  
end
