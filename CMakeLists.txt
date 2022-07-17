cmake_minimum_required(VERSION 3.22)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(PICO_SDK_FETCH_FROM_GIT on)
set(PICO_BOARD pico_w)
add_compile_options(-Wall
        -Wno-format          # int != int32_t as far as the compiler is concerned because gcc has int32_t as long int
        -Wno-unused-function # we have some for the docs that aren't called
        -Wno-maybe-uninitialized
        )

include(${CMAKE_CURRENT_LIST_DIR}/cmake/pico_sdk_import.cmake)
project(pico)
pico_sdk_init()

add_executable(pico main.cpp)
target_link_libraries(pico pico_stdlib pico_cyw43_arch_none)
pico_add_extra_outputs(pico)
#set_target_properties( pico PROPERTIES SUFFIX ".uf2")
