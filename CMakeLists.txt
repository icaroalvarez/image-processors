cmake_minimum_required(VERSION 3.5)

project(ImageProcessors)
set(CMAKE_CXX_STANDARD 17)
message("CMake build type: " ${CMAKE_BUILD_TYPE})

include(.conan/conanbuildinfo.cmake)
conan_basic_setup()
message(${CONAN_INCLUDE_DIRS})
find_package(OpenCV REQUIRED COMPONENTS core highgui)

if (NOT TARGET panoramix)
    add_subdirectory(modules/panoramix)
endif ()
message(${CONAN_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(test)