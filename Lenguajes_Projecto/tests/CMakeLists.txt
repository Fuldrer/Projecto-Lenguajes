cmake_minimum_required (VERSION 2.6)
project (test_lexer)

set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++17" )

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/../)
  
add_executable(${PROJECT_NAME} 
                    ${PROJECT_SOURCE_DIR}/../evaluador.cpp
                    ../valinfijo.cpp
                    test_lexer.cpp)

enable_testing()
add_test(NAME ${PROJECT_NAME}
         COMMAND ${PROJECT_NAME})
