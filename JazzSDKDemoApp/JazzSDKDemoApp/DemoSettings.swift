//
//  DemoJazzSettings.swift
//  DemoApp
//
//  Created by Бузырев Илья Леонидович on 01.03.2023.
//

import Foundation
import JazzSDK

extension JazzSettings {
	/// Демонстрационные настройки для работы Jazz.
	/// Более поробно см. `JazzSettings`
	static let demoSettings = JazzSettings(
		network: JazzNetwork(
			hostUrl: URL(string: "https://jazz.sber.ru")!
		),
		buttonsVisibility: .allVisible,
		inviteButton: nil,
		screenShareExtensionIdentifier: nil,
		userNameService: nil
	)
}
