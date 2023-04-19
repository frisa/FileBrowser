cmake_minimum_required(VERSION 3.1...3.26)

project(
    FileBrowser
    VERSION 1.0
    LANGUAGES CXX)

add_executable(FileBrowser)

target_sources(FileBrowser 
    PRIVATE 
        program.cpp)

target_sources(FileBrowser 
    PRIVATE 
        SystemInfo.cpp
        Cpp11_AutoDecltype.cpp
    PUBLIC
        SystemInfo.hpp
        Cpp11_AutoDecltype.hpp
    )