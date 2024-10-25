cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17")

set(wxBUILD_SHARED OFF)

project(zwei_takt_rechner VERSION 1.0.0 LANGUAGES CXX)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()
add_executable(myapp mainApp.cpp mainApp.h myframe.cpp myframe.h)
target_link_libraries(myapp ${wxWidgets_LIBRARIES})