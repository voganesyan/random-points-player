cmake_minimum_required(VERSION 3.16)
project(random-points-player LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Charts Core Gui)

qt_add_executable(random-points-player
    mainwindow.cpp mainwindow.h
    chartview.cpp chartview.h
    main.cpp
)

target_link_libraries(random-points-player PUBLIC
    Qt::Charts
    Qt::Core
    Qt::Gui
)
