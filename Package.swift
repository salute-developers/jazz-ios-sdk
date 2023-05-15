// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "JazzSDK",
    platforms: [
        .iOS(.v15),
    ],
    products: [
        .library(
            name: "JazzSDK",
            targets: ["JazzSDK", "LibSberCast", "JazzCore", "WebRTC", "JazzScreenShareImpl", "SDSoup"]),
    ],
    targets: [
        .binaryTarget(
            name: "JazzSDK",
            path: "Sources/JazzSDK.xcframework"
        ),
        .binaryTarget(
            name: "LibSberCast",
            path: "Sources/LibSberCast.xcframework"
        ),
        .binaryTarget(
            name: "JazzCore",
            path: "Sources/JazzCore.xcframework"
        ),
        .binaryTarget(
            name: "WebRTC",
            path: "Sources/WebRTC.xcframework"
        ),
        .binaryTarget(
            name: "JazzScreenShareImpl",
            path: "Sources/JazzScreenShareImpl.xcframework"
        ),
        .binaryTarget(
            name: "SDSoup",
            path: "Sources/SDSoup.xcframework"
        ),
    ]
)
