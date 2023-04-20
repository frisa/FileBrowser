cmake_minimum_required(VERSION 3.1...3.26)

project(
    FileBrowser
    VERSION 1.0
    LANGUAGES CXX)

add_executable(FileBrowser)

target_sources(FileBrowser 
    PRIVATE
        #program.cpp
        qtprogram.cpp 
        SystemInfo.cpp
        Cpp11_AutoDecltype.cpp
    PUBLIC
        SystemInfo.hpp
        Cpp11_AutoDecltype.hpp
    )

set_property(
    TARGET
        FileBrowser
    PROPERTY
        CXX_STANDARD 17)

# Qt specific stuff
set(CMAKE_PREFIX_PATH "/Users/jan/Qt/6.5.0/macos/lib/cmake/Qt6")
find_package(Qt6 REQUIRED COMPONENTS Core)
qt_standard_project_setup()
target_link_libraries(FileBrowser PRIVATE Qt6::Core)