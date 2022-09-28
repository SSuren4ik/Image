cmake_minimum_required(VERSION  3.10 FATAL_ERROR)

project(Image)

include(cmake/function.cmake)
add_subdirectory(MyLib)

add_subdirectory(Main)

option(BTEST "build test?" OFF)

if(BTEST)
    add_subdirectory(gtest)
    add_subdirectory(test)
endif()
