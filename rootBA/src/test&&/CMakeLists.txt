cmake_minimum_required( VERSION 3.10 )
project(test)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++11 ${SSE_FLAGS} -g -O3 -march=native")
find_package( TBB REQUIRED )
add_executable( test1
        test1.cpp
        )
add_executable( testgivens
        testgivens.cpp
        )


