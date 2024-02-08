cmake_minimum_required(VERSION 3.17)
project(jotty)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/usr")

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(jotty
        main.cpp
        JottyWindow.cpp
        JottyEditor.cpp
        ConfigManager.cpp
        JottyWindow.h
        JottyEditor.h
        ConfigManager.h
)

target_link_libraries(jotty Qt6::Widgets)
