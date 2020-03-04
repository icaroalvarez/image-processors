cmake_minimum_required(VERSION 3.5)

project(ImageProcessors)
set(CMAKE_CXX_STANDARD 17)

include(.conan/conanbuildinfo.cmake)
get_directory_property(hasParent PARENT_DIRECTORY)
if(!hasParent)
    conan_basic_setup(TARGETS)
endif()

if (NOT TARGET panoramix)
    add_subdirectory(modules/panoramix)
endif ()

add_subdirectory(src)
add_subdirectory(test)