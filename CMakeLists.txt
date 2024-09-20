cmake_minimum_required(VERSION 3.5)

project(Calc VERSION 0.0 LANGUAGES CXX)

find_package(FLEX 2.6 REQUIRED)
find_package(BISON 3.0 REQUIRED)

set(PARSER_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(LEXER_OUT "${PARSER_DIR}/lexer.cpp")
set(PARSER_OUT "${PARSER_DIR}/parser.cpp")

flex_target(LEXER lexer.ll "${LEXER_OUT}" DEFINES_FILE "${PARSER_DIR}/lexer.h")
bison_target(PARSER parser.yy "${PARSER_OUT}" DEFINES_FILE "${PARSER_DIR}/parser.h")
add_flex_bison_dependency(LEXER PARSER)

add_executable(calc main.cpp "${LEXER_OUT}" "${PARSER_OUT}")
target_include_directories(calc PRIVATE "${PARSER_DIR}")
