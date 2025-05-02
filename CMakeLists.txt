
cmake_minimum_required(VERSION 3.20)

project(
        raytracer
        VERSION 1.0
        DESCRIPTION "Raytracer Engine"
        LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})



file(GLOB_RECURSE CORE_SRC "src/*.cpp")
file(GLOB_RECURSE CORE_INC "src/*.hpp")

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBCONFIG REQUIRED libconfig++)

add_executable(${PROJECT_NAME} ${CORE_SRC} ${CORE_INC})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/ ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(${PROJECT_NAME} PRIVATE ${LIBCONFIG_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBCONFIG_LIBRARIES})

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -lconfig++)