cmake_minimum_required(VERSION 3.8)
project(cam3d-tests)

add_executable(${PROJECT_NAME} tests.cpp)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wconversion -Wsign-conversion)
endif()

set(CAM3D_ENABLE_WARNINGS_AS_ERRORS ON)
add_subdirectory(.. ${CMAKE_CURRENT_SOURCE_DIR}/build/cam3d)
target_link_libraries(${PROJECT_NAME} PRIVATE cam3d::cam3d)

add_subdirectory(doctest)
target_link_libraries(${PROJECT_NAME} PRIVATE doctest::doctest)