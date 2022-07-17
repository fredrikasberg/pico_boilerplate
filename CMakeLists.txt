cmake_minimum_required(VERSION 3.22)

## Project configuration
set(PROJECT_NAME "pico-w_boilerplate")
set(PICO_BOARD "pico_w") # pico or pico_w

## Default setup
set(${PROJECT_NAME}_ENTRYPOINT ${CMAKE_CURRENT_LIST_DIR}/main.cpp) # default entrypoint
set(${PROJECT_NAME}_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/include)
set(${PROJECT_NAME}_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_SDK_FETCH_FROM_GIT on)
add_compile_options(-Wall -Wno-format -Wno-unused-function -Wno-maybe-uninitialized)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/pico_sdk_import.cmake)
project(${PROJECT_NAME} C CXX ASM)
pico_sdk_init()
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
file(GLOB_RECURSE ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_SOURCE_DIR}/*.cpp)
add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_ENTRYPOINT} ${${PROJECT_NAME}_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} pico_stdlib)
if (PICO_CYW43_SUPPORTED)
    target_link_libraries(${PROJECT_NAME} pico_cyw43_arch_none)
endif ()
pico_add_extra_outputs(${PROJECT_NAME})
