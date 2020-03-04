cmake_minimum_required(VERSION 3.5)

set(source_files
        ResizeImage
        Roi
        Mosaic
        Registerer
        AdaptiveThreshold
        ColorSpace
        Convolution)

add_library(image_processors
        ${source_files}
        )

target_link_libraries(image_processors PRIVATE
        panoramix
        PUBLIC
        CONAN_PKG::opencv
        )

target_include_directories(image_processors PUBLIC
        ../src
        )
