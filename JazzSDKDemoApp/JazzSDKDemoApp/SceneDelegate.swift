//
//  SceneDelegate.swift
//  DemoApp
//
//  Created by Бузырев Илья Леонидович on 28.02.2023.
//

import JazzSDK
import SwiftUI
import UIKit

class SceneDelegate: UIResponder, UIWindowSceneDelegate {
	var window: UIWindow?

	func scene(_ scene: UIScene, willConnectTo _: UISceneSession, options _: UIScene.ConnectionOptions) {
		guard let windowScene = (scene as? UIWindowScene) else { return }
		/// Для инициализации JazzSDK необходимо создать `UIViewController`
		/// приложения, который в последствии будет передан в Jazz
		let rootViewController = UIHostingController(rootView: DemoAppView())

		/// Для корректной работы Jazz необходимо передать уникальный ключ SDK,
		/// который был получен после регистрации приложения.
		/// - important: Если передать неправильный ключ, то приложение не будет работать!
		let sdkSecret = "eyJwcm9qZWN0SWQiOiIwNTRkMGFjMy0zODE4LTRhMzctYjk2Mi03NDMxNTg1NDhmM2YiLCJrZXkiOnsia3R5IjoiRUMiLCJkIjoiMDg0b3EtRlVzRnE4UkgyRU9GRG9SNlBlVy1mb0V0LWtGNXZsbUVqQkxfQktvMzJyTFdnSnphdjhLeTZDc0IzQyIsInVzZSI6ImVuYyIsImNydiI6IlAtMzg0Iiwia2lkIjoiOGI5OTE0YmYtZGVlYy00YWEwLWI4ZDgtNWJhYzA1MzJmZTc0IiwieCI6IjFJNkZISnlkbW9YcmNabHhKT3BudnFZY0pqX2NGZEw5UENNQWIyd0VTQ3JCRnYxcGhRVU9LM2tsdGk5REF4WnQiLCJ5Ijoid0JTOU5ac3MtMXd1c1daOXJRU2tVS3M1T2h5QXF2Qkc1SWtVUnR1UDZjUjJwYjRQZW9KcEl5NU0yUmNmMkloeiJ9fQ=="
		/// Для работы с Jazz необходима сущность, передающая Конфигурацию токена приложения.
		/// Более подробно про конфигурацию см. `JazzTokenConfiguration`
		let tokenConfigurationProvider = DemoTokenConfigurationProvider()
		/// Изначальные настройки приложения, такие как ссылки на бекенд и хост приложения, видимость кнопок в приложении,
		/// настройка дополнительной кнопки в меню пригласить, идентификатор ScreenSharing'а для корректной работы функции
		/// демнострации экрана и сервис для хранения и изменения имени пользователя в приложении
		let settings = JazzSettings.demoSettings
		/// Инициализация Jazz в приложении.
		/// - important: Если не провести инициализацию приложения, то будет недоступен функционал SDK и при попытке вызова
		/// функций, приложение будет выдавать ошибку авторизации
		try? Jazz.initialize(
			sdkSecret: sdkSecret,
			tokenConfigurationProvider: tokenConfigurationProvider,
			container: rootViewController,
			settings: settings
		)

		window = UIWindow(frame: windowScene.coordinateSpace.bounds)
		window?.windowScene = windowScene
		window?.makeKeyAndVisible()
		window?.rootViewController = rootViewController
	}
}
