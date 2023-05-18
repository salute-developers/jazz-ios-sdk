Pod::Spec.new do |spec|
  spec.name         = 'JazzSDK'
  spec.version      = '23.4.1'
  spec.platform = :ios, '14.0'
  spec.license      = { :type => 'MIT', :file => 'LICENCE.MD' }
  spec.homepage     = 'https://developers.sber.ru/portal/products/sberjazz/sdk'
  spec.author      = 'SaluteDevices'
  spec.summary      = 'Jazz SDK for iOS'
  spec.source       = { :git => 'https://github.com/salute-developers/jazz-ios-sdk.git' }
  spec.ios.vendored_frameworks = 'JazzSDK.xcframework'
  
  spec.swift_version = '5.0'
  spec.ios.deployment_target = '14.0'
  
end
