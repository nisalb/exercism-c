cmake_minimum_required(VERSION 3.15)
project(isogram)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)
include_directories(test)
include_directories(test/vendor)

add_executable(isogram
        src/isogram.c
        src/isogram.h
        test/vendor/unity.c
        test/vendor/unity.h
        test/vendor/unity_internals.h
        test/test_isogram.c)
