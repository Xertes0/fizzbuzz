add_executable(main)

set_property(TARGET main PROPERTY EXPORT_COMPILE_COMMANDS ON)
set_property(TARGET main PROPERTY CXX_STANDARD 20)

target_sources(main PRIVATE ./src/main.cxx)

target_link_libraries(main PRIVATE fizzbuzz)
