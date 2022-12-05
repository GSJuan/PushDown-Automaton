cmake_minimum_required(VERSION 3.0.0)
project(PushDown-Automaton VERSION 0.1.0)

# This sets the variable SOURCES to be the list of source files
set(SOURCES
    main.cpp 
    src/automaton.cpp
)

#include(CTest)
#enable_testing()

# This defines your project to build an executable 'my_exe' from the sources
add_executable(PushDown-Automaton ${SOURCES})

# This adds the folder 'include' as a search path for the compiler
target_include_directories(PushDown-Automaton 
    PRIVATE 
      ${PROJECT_SOURCE_DIR}/include
)

# this add the relative path to the test folder as a c++ usable macro
target_compile_definitions(PushDown-Automaton PUBLIC TEST_RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/test/")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
