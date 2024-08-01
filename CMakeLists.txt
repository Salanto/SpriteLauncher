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
    data/data.qrc
)

target_link_libraries(SpriteLauncher PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
)

include(GNUInstallDirs)
install(TARGETS SpriteLauncher
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
