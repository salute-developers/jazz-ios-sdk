//
//  TokenConfigurationProvider.swift
//  DemoApp
//
//  Created by Бузырев Илья Леонидович on 01.03.2023.
//

import JazzSDK

/// Демонстрационный сервис для передачи токена Jazz.
/// Более подробно см. `JazzTokenConfigurationProvider`
final class DemoTokenConfigurationProvider: JazzTokenConfigurationProvider {
	func provideTokenConfiguration() -> JazzTokenConfiguration {
		JazzTokenConfiguration(
			timeToLive: 120,
			issuer: "JazzSDKDemoApp",
			userId: "123456",
			userName: nil,
			userEmail: nil
		)
	}
}
