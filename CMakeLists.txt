cmake_minimum_required(VERSION 3.5)
project(SHA512)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        const.h
        main.cpp
        sha.h
        sha512.cpp
        sha512.hpp
        types.h)

add_executable(SHA512 ${SOURCE_FILES})
