project(nanaguru)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE "Release")

INCLUDE_DIRECTORIES(${CMAKE_BINARY_DIR}/zlib-1.2.8)

add_subdirectory(zlib-1.2.8)

if( CMAKE_BUILD_TYPE STREQUAL "Release" )
    set(ZLIB_LIBRARY "../zlib-1.2.8/zlib")
endif( CMAKE_BUILD_TYPE STREQUAL "Release" )

if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
    set(ZLIB_LIBRARY "../zlib-1.2.8/zlibd")
endif( CMAKE_BUILD_TYPE STREQUAL "Debug" )

set(ZLIB_INCLUDE_DIR "../zlib-1.2.8/")

add_subdirectory(lpng158)

set(CMAKE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/nana)

add_definitions( -DNANA_WINDOWS -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_DEPRECATE )
add_definitions( -DNANA_UNICODE -DUNICODE -D_UNICODE )

add_subdirectory(nana)

SET_TARGET_PROPERTIES(nana PROPERTIES LINKER_LANGUAGE CXX)

add_subdirectory(examples)
