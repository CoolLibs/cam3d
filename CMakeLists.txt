cmake_minimum_required(VERSION 3.8)

set(WARNINGS_AS_ERRORS_FOR_CAM3D OFF CACHE BOOL "ON iff you want to treat warnings as errors")

add_library(cam3d)
add_library(cam3d::cam3d ALIAS cam3d)
target_compile_features(cam3d PUBLIC cxx_std_17)

# ---Add source files---
if(WARNINGS_AS_ERRORS_FOR_CAM3D)
    target_include_directories(cam3d PUBLIC include)
else()
    target_include_directories(cam3d SYSTEM PUBLIC include)
endif()

target_sources(cam3d PRIVATE
    src/cam3d.cpp
)

# Set warning level
if(MSVC)
    target_compile_options(cam3d PRIVATE /W4)
else()
    target_compile_options(cam3d PRIVATE -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

# Maybe enable warnings as errors
if(WARNINGS_AS_ERRORS_FOR_CAM3D)
    if(MSVC)
        target_compile_options(cam3d PRIVATE /WX)
    else()
        target_compile_options(cam3d PRIVATE -Werror)
    endif()
endif()