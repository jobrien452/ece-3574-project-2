cmake_minimum_required(VERSION 3.2)
project(QtMarkup CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(ENABLE_CXX11 "-std=c++11")
find_package(Qt4 REQUIRED QtTest )
INCLUDE(${QT_USE_FILE})

#QT4_WRAP_CPP(MOCSrcs window.h parse.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

add_executable(qtdraw main.cpp drawing.cpp qtdraw.cpp line.cpp circle.cpp canvas.cpp menu.cpp window.cpp message.cpp)
add_executable(linetest lineTest.cpp line.cpp qtdraw.cpp)
add_executable(circletest circleTest.cpp circle.cpp qtdraw.cpp)
add_executable(canvastest canvasTest.cpp canvas.cpp qtdraw.cpp)
add_executable(messagetest messageTest.cpp message.cpp)
add_executable(menutest menuTest.cpp menu.cpp)
add_executable(drawingtest drawingTest.cpp drawing.cpp qtdraw.cpp line.cpp circle.cpp canvas.cpp)
add_executable(qtdrawtest qtdrawTest.cpp qtdraw.cpp line.cpp)

target_link_libraries(qtdraw Qt4::QtGui)
target_link_libraries(linetest Qt4::QtTest Qt4::QtGui)
target_link_libraries(circletest Qt4::QtTest Qt4::QtGui)
target_link_libraries(canvastest Qt4::QtTest Qt4::QtGui)
target_link_libraries(messagetest Qt4::QtTest Qt4::QtGui)
target_link_libraries(menutest Qt4::QtTest Qt4::QtGui)
target_link_libraries(drawingtest Qt4::QtTest Qt4::QtGui)
target_link_libraries(qtdrawtest Qt4::QtTest Qt4::QtGui)

enable_testing()

add_test(linetest linetest)
add_test(circletest circletest)
add_test(canvastest canvastest)
add_test(messagetest messagetest)
add_test(menutest menutest)
add_test(drawingtest drawingtest)
add_test(qtdrawtest qtdrawtest)


