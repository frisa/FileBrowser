cmake_minimum_required(VERSION 3.1...3.26)

IF(APPLE)
    set(CMAKE_PREFIX_PATH "/Users/jan/Qt/6.5.0/macos/lib/cmake/Qt6")
ELSE()
    set(CMAKE_PREFIX_PATH "/home/jan/Qt/6.5.0/gcc_64")
ENDIF()

project(FileBrowser VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Gui QuickControls2)

qt_standard_project_setup()
qt_add_executable(fileBrowser ./src/program.cpp)
target_include_directories(fileBrowser 
    PRIVATE
        "~/Qt/6.5.0/macos/lib/QtCore.framework/Headers"
        "~/Qt/6.5.0/macos/lib/QtQml.framework/Headers"
        "~/Qt/6.5.0/macos/lib/QtGui.framework/Headers"
        "~/Repository/FileBrowser/inc"
    )

target_sources(fileBrowser
    PRIVATE
        src/program.cpp
        src/SystemInfo.cpp
    PUBLIC
        inc/SystemInfo.hpp
    )

set_source_files_properties(qml/main.qml PROPERTIES QT_RESOURCE_ALIAS main.qml)
qt_add_qml_module(fileBrowser 
    URI 
        main
    RESOURCE_PREFIX 
        /qt/qml/ui
    QML_FILES  
        qml/main.qml
        qml/FormField.qml)

target_link_libraries(fileBrowser PRIVATE Qt6::Gui Qt6::Qml Qt6::QuickControls2)
