add_library(fizzbuzz INTERFACE)

file(GLOB_RECURSE SOURCES ./include/*.hxx)

target_sources(fizzbuzz INTERFACE ${SOURCES})
target_include_directories(fizzbuzz INTERFACE ./include)
