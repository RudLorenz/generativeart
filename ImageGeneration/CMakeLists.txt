cmake_minimum_required(VERSION 3.12)
project(ImageGeneration)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion \
 -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC")

add_executable(ImageGeneration main.cpp src/bitmapimg.h src/bmpheader.h src/idrawable.h src/point.h src/line.h src/polygon.h src/gradient.h)