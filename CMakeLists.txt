cmake_minimum_required(VERSION 3.22)

project(FizzBuzz VERSION 0.1 LANGUAGES CXX)

add_executable(main)

set_property(TARGET main PROPERTY EXPORT_COMPILE_COMMANDS ON)
set_property(TARGET main PROPERTY CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES *.cxx *.hxx)
target_sources(main PRIVATE ${SOURCES})

target_link_libraries(main PRIVATE)
