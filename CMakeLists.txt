cmake_minimum_required(VERSION 3.8)

add_library(cam3d)
add_library(cam3d::cam3d ALIAS cam3d)
target_compile_features(cam3d PUBLIC cxx_std_20)
# ---Add source files---
target_include_directories(cam3d PUBLIC include)
target_sources(cam3d PRIVATE
    src/cam3d.cpp
)

if (CAM3D_ENABLE_WARNINGS_AS_ERRORS)
    message("-- [cam3d] Enabling warnings as errors for cam3d")
    if(MSVC)
        target_compile_options(cam3d PRIVATE /WX /W4)
    else()
        target_compile_options(cam3d PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
    endif()
else()
    message("-- [cam3d] Not using warnings as errors for cam3d")
endif()