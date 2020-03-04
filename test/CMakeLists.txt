cmake_minimum_required(VERSION 3.5)

set(test_source_files
        main.test.cpp
        Mosaic.Test.cpp
        )

add_executable(test_image_processors
        ${test_source_files}
        )

target_link_libraries(test_image_processors
        PRIVATE image_processors CONAN_PKG::Catch2
        )

target_compile_definitions(test_image_processors
        PRIVATE fixtures_path="${CMAKE_CURRENT_SOURCE_DIR}/fixtures/"
        )