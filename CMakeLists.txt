cmake_minimum_required(VERSION 3.14)

project(SpriteLauncher LANGUAGES CXX)
include(version.cmake)

configure_file(templates/version.h.in ${PROJECT_SOURCE_DIR}/src/version.h)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6)
find_package(Qt6 REQUIRED COMPONENTS Core Network Gui Widgets UiTools)

add_executable(SpriteLauncher
    src/main.cpp
    src/downloadmanager.h src/downloadmanager.cpp
    src/configloader.h src/configloader.cpp
    src/version.h
    src/filefunctions.h src/filefunctions.cpp
    src/launcher.h src/launcher.cpp
    src/launcheruserinterface.h src/launcheruserinterface.cpp
    src/settingsuserdialog.h src/settingsuserdialog.cpp
    src/download.h src/download.cpp
    data/data.qrc
    src/temporarydirectory.h src/temporarydirectory.cpp
    src/gui_utils.h
)

target_link_libraries(SpriteLauncher PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    Qt6::UiTools
)

set_target_properties(SpriteLauncher PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY $<1:${CMAKE_CURRENT_LIST_DIR}/bin>
    RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_CURRENT_LIST_DIR}/bin>)


if(WIN32)
    set_property(TARGET SpriteLauncher PROPERTY WIN32_EXECUTABLE true)
    set(APP_ICON_RESOURCE_WINDOWS "${CMAKE_CURRENT_SOURCE_DIR}/data/logo/logo.rc")
    target_sources(SpriteLauncher PRIVATE ${APP_ICON_RESOURCE_WINDOWS})
endif()

