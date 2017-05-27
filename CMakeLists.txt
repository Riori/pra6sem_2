cmake_minimum_required(VERSION 3.5)
project(compute_sha512_hash)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_LIB_FILES
        sha512.cpp
)
set(HEADERS
	const.h
	sha512.hpp
	types.h
)
set(SOURCE
	main.cpp
)

add_library(sha512 STATIC ${SOURCE_LIB_FILES} ${HEADERS})
add_executable(compute_sha512_hash ${SOURCE} ${HEADERS})

target_link_libraries(compute_sha512_hash sha512)
