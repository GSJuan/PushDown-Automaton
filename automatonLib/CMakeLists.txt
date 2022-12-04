add_library(automatonLib src/automaton.cpp)
 
message("Automaton current source dir = ${CMAKE_CURRENT_SOURCE_DIR}")
 
target_include_directories( automatonLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
