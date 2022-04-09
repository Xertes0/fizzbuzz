file(GLOB_RECURSE EXAMPLES ./src/*.cxx)

foreach(EXAMPLE_PATH IN LISTS EXAMPLES)
  get_filename_component(NAME ${EXAMPLE_PATH} NAME_WLE)

  add_executable(${NAME})

  set_property(TARGET ${NAME} PROPERTY EXPORT_COMPILE_COMMANDS ON)
  set_property(TARGET ${NAME} PROPERTY CXX_STANDARD 20)

  target_sources(${NAME} PRIVATE ${EXAMPLE_PATH})

  target_link_libraries(${NAME} PRIVATE fizzbuzz)

endforeach()
