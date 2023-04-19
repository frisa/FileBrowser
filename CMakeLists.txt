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
        TestCls.cpp
    PUBLIC
        SystemInfo.hpp
        TestCls.hpp
    )