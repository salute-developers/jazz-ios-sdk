// swift-tools-version: 5.8
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "JazzSDK",
    products: [
        .library(
            name: "JazzSDK",
            targets: ["JazzSDK", "LibSberCast", "JazzCore", "WebRTC", "JazzResources", "DevicesDesignSystemResources"]),
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
        .target(
            name: "JazzResources",
            resources: [
                .process("JazzResources.bundle")
            ],
            path: "Sources/JazzResources.bundle"
        ),
        .target(
            name: "DevicesDesignSystemResources",
            resources: [
                .process("DevicesDesignSystemResources.bundle")
            ],
            path: "Sources/DevicesDesignSystemResources.bundle"
        )
    ]
)
