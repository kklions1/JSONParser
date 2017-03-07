#to be set up as a CMakeLists file
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-std=c++14")
include_directories(.)

add_executable(jsonParser
    helper.cpp
    main.cpp)
    
