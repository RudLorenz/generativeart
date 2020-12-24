cmake_minimum_required(VERSION 3.15)
project(ImageGeneration)

add_executable(imagegeneration)

target_compile_features(imagegeneration PUBLIC cxx_std_17)

target_include_directories(imagegeneration PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_sources(imagegeneration
        PUBLIC include/bitmapimg.h include/bmpheader.h include/idrawable.h include/icolor.h include/point.h
            include/line.h include/polygon.h include/gradient.h include/gradient3.h include/solidcolor.h
            include/ccs.h include/plotfunction.h
        PRIVATE main.cpp src/bitmapimg.cpp src/bmpheader.cpp src/point.cpp src/line.cpp src/polygon.cpp
            src/gradient.cpp src/gradient3.cpp src/solidcolor.cpp src/ccs.cpp src/plotfunction.cpp)

target_compile_options(imagegeneration PRIVATE
        $<$<CONFIG:Debug>: -Wall -Wextra -Wpedantic -fno-omit-frame-pointer -fsanitize=address -g>)

target_link_options(imagegeneration PRIVATE
        $<$<CONFIG:Debug>: -fno-omit-frame-pointer -fsanitize=address>)
