cmake_minimum_required(VERSION 3.14)
project(CadexCurves LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(curves_app
    main.cpp
    curves/Circle.cpp
    curves/Ellipse.cpp
    curves/Helix.cpp
    utils/Parser.cpp
    utils/Printer.cpp
)

target_include_directories(curves_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/curves
    ${CMAKE_CURRENT_SOURCE_DIR}/utils
)

target_compile_options(curves_app PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4 /WX>
    $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Werror>
)