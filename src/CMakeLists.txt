cmake_minimum_required(VERSION 3.5)

set(source_files
        ResizeImage
        Roi
        Mosaic)

add_library(image_processors
        ${source_files}
        )

target_link_libraries(image_processors PRIVATE
        image_processor_base
        opencv_core)

target_include_directories(image_processors PRIVATE
        ../src
        ../modules/image-processor-base/src
        )
