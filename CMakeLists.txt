cmake_minimum_required(VERSION 3.5)

project(ImageProcessor)
set(CMAKE_CXX_STANDARD 17)
message("CMake build type: " ${CMAKE_BUILD_TYPE})

set(SOURCES_DIR
        ${CMAKE_SOURCE_DIR}/src/)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
find_package(OpenCV REQUIRED COMPONENTS core highgui)

if (NOT TARGET image-processor-base)
    add_subdirectory(modules/image-processor-base)
endif ()

add_subdirectory(src)
add_subdirectory(test)