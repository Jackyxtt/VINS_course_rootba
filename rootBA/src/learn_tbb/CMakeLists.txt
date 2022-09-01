cmake_minimum_required( VERSION 3.10 )
project(learn_tbb)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "-std=c++11 ${SSE_FLAGS} -g -O3 -march=native")
find_package( TBB REQUIRED )
add_executable( example1
        example1.cpp
        )
# 链接库到可执行文件
target_link_libraries( example1
        TBB::tbb
        )

add_executable( example2
        example2.cpp
        )
# 链接库到可执行文件
target_link_libraries( example2
        TBB::tbb
        )