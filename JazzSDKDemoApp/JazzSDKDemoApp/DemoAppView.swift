//
//  DemoAppView.swift
//  DemoApp
//
//  Created by Бузырев Илья Леонидович on 01.03.2023.
//

import JazzSDK
import SwiftUI

struct DemoAppView: View {
	@State var roomId: String = ""
	@State var roomPassword: String = ""
	@State var urlString: String = ""

	/// - important: Если до вызова функций из `JazzSession.shared`  не произвести `Jazz.initialize`, то приложение вызовет ошибку.
	var body: some View {
		VStack(spacing: 10) {
			Button("Создать конференцию") {
				/// Создание обычной конференции. Совершает переход на экран создания конференции.
				/// Получает в параметрах конфигурацию конференции (см. `JazzConferenceConfiguration`),
				/// и completion, который отдает ссылку на созданную конференцию.
				JazzSession.shared.createConference(
					configuration: JazzConferenceConfiguration(
						title: "Demo title",
                        type: "meeting",
						settings: JazzConferenceSettings(
                            isGuestsOn: true,
                            isLobbyOn: false,
                            isAutoRecordEnabled: false
                        )
					),
					completion: { url in
						print(url)
					}
				)
			}
			Button("Начать конференцию") {
				/// Создание обычной конференции и присоединение к ней. Совершает переход на экран создания конференции.
				/// Получает в параметрах конфигурацию конференции (см. `JazzConferenceConfiguration`), настройки источников
				/// медиа (см. `JazzConferenceMediaSettings`), тип конференции для событий аналитики и предпочтительный
				/// тип динамика для начала конференции (например, если поставить `reciver`, то конференция будет начинаться со
				/// звуком из тихого динамика.
				JazzSession.shared.startConference(
					configuration: JazzConferenceConfiguration(
						title: "Demo title",
						type: "meeting",
						settings: JazzConferenceSettings(
							isGuestsOn: true,
							isLobbyOn: false,
							isAutoRecordEnabled: false
						)
					),
					mediaSettings: JazzConferenceMediaSettings(
						isCameraOn: false,
						isMicrophoneOn: false
					),
					analyticsConferenceType: nil,
                    preferredSpeaker: nil
				)
			}
			Button("Присоединиться к конференции") {
				/// Присоединение к конференции. Совершает переход на экран присоединения к конференции.
				/// Получает в параметрах ID и пароль конференции, к которой нужно подключиться, настройки источников медиа
				/// (см. `JazzConferenceMediaSettings`) и тип конференции для событий аналитики.
				JazzSession.shared.joinConference(
					mediaSettings: JazzConferenceMediaSettings(
						isCameraOn: false,
						isMicrophoneOn: false
					),
					analyticsConferenceType: nil
				)
			}
			HStack(spacing: 10) {
				DemoTextField(placeholder: "Код встречи", text: $roomId)
				DemoTextField(placeholder: "Пароль встречи", text: $roomPassword)
			}
			Button("Завершить текущую конференцию") {
				/// Завершение текущей конференции.
				JazzSession.shared.terminateActiveConference()
			}
			Button("Обработать апп или диплинк") {
				if let url = URL(string: urlString) {
					/// Обработка апплинков и диплинков в приложении. Выдает результат обработки, который в последствии можно использовать для присоединения к приложению
                    JazzSession.shared.handle(url: url, type: .applink)
				}
			}
			DemoTextField(placeholder: "Ссылка", text: $urlString)
		}
	}
}

struct DemoTextField: View {
	let placeholder: String
	@Binding var text: String
	var body: some View {
		TextField(placeholder, text: $text)
			.padding()
			.cornerRadius(5)
			.border(.black)
	}
}
