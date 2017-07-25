cmake_minimum_required(VERSION 3.5)
project(towerdefency)

set(CMAKE_CURRENT_INCLUDE_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)

set(Qt_Lib Qt5::Widgets Qt5::Gui Qt5::Core)


file(GLOB HDR src/*.h)
file(GLOB SRC src/*.cc)

qt5_add_resources(RC src/towerdefency.qrc)

add_executable(towerdefency WIN32 ${HDR} ${SRC} ${RC})
target_link_libraries(towerdefency ${Qt_Lib})
