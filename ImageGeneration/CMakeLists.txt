cmake_minimum_required(VERSION 3.12)
project(ImageGeneration)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra -pedantic -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion \
 -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC \
  -D_FORTIFY_SOURCE=2 -fstack-protector")

add_executable(ImageGeneration main.cpp bmpgen.cpp bmpgen.h bmpheader.h)