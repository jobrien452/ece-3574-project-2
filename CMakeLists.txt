cmake_minimum_required(VERSION 3.2)
project(QtMarkup CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt4 REQUIRED QtTest )
INCLUDE(${QT_USE_FILE})

#QT4_WRAP_CPP(MOCSrcs window.h parse.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_executable(qtdraw main.cpp drawing.cpp qtdraw.cpp line.cpp) # ${MOCSrcs})

target_link_libraries(qtdraw Qt4::QtGui)

enable_testing()
