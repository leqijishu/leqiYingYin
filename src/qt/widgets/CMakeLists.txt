cmake_minimum_required(VERSION 3.5)

project(leqiyingyin VERSION 0.6 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia  MultimediaWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia  MultimediaWidgets)

set(PROJECT_SOURCES
        main.cpp leqiyingyin.h leqiyingyin.cpp leqivideowidget.h leqivideowidget.cpp
        leqibutton.h leqibutton.cpp constants.h leqititlebar.h leqititlebar.cpp
        leqicontrolbar.h leqicontrolbar.cpp leqicontrols.h leqicontrols.cpp
        leqimenu.h leqimenu.cpp leqislider.h leqislider.cpp
)

set(app_icon_windows "${CMAKE_CURRENT_SOURCE_DIR}/resources/logo/leqiyingyin.rc")

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(leqiyingyin
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${app_icon_windows}
    )
else()
    if(ANDROID)
        add_library(leqiyingyin SHARED
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(leqiyingyin PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia  Qt${QT_VERSION_MAJOR}::MultimediaWidgets)

set_target_properties(leqiyingyin PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER gitee.com.leqijishu
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

set(assets_resource_files
    "resources/qss/dark.qss"
    "resources/logo/leqi.ico"
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
    "resources/images/handle.svg"
)

qt_add_resources(leqiyingyin "assets"
    PREFIX
        "/"
    FILES
        ${assets_resource_files}
)

install(TARGETS leqiyingyin
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(leqiyingyin)
endif()
