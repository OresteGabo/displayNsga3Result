cmake_minimum_required(VERSION 3.28)
project(displayNsga3Result)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        PrintSupport
        REQUIRED)

add_executable(displayNsga3Result main.cpp
        qcustomplot/qcustomplot.cpp
)
target_link_libraries(displayNsga3Result
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::PrintSupport
)

