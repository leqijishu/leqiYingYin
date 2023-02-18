cmake_minimum_required(VERSION 3.16)

project(leqiyingyin VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(leqiyingyin
    main.cpp
)

set(qmlfiles
    main.qml TitleBar.qml ControlBar.qml
)

qt_add_qml_module(leqiyingyin
    URI leqiyingyin
    VERSION 1.0
    QML_FILES ${qmlfiles}
)

set(assets_files
    "resources/logo/logo32.png"
    "resources/images/fullscreen-8a.svg"
    "resources/images/fullscreen.svg"
    "resources/images/minimize-8a.svg"
    "resources/images/minimize.svg"
    "resources/images/close-8a.svg"
    "resources/images/close.svg"
    "resources/images/ontop.svg"
    "resources/images/open-8a.svg"
    "resources/images/open.svg"
    "resources/images/play-8a.svg"
    "resources/images/play.svg"
    "resources/images/pause-8a.svg"
    "resources/images/pause.svg"
    "resources/images/stop-8a.svg"
    "resources/images/stop.svg"
    "resources/images/voice-8a.svg"
    "resources/images/voice.svg"
    "resources/images/mute-8a.svg"
    "resources/images/mute.svg"
)

qt_add_resources(leqiyingyin "assets"
    PREFIX
        "/"
    FILES
        ${assets_files}
)

set_target_properties(leqiyingyin PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER gitee.com.leqijishu
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(leqiyingyin
    PRIVATE Qt6::Quick)

install(TARGETS leqiyingyin
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
