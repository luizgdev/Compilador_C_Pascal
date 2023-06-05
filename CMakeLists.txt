cmake_minimum_required(VERSION 3.25)
project(C_Pascal_Compiler C)

set(CMAKE_C_STANDARD 11)

add_executable(analisadorLexico main.c tests/test_lexer.pas lexer/lexer.c lexer/lexer.h utils/hash_table/hash.c utils/hash_table/hash.h parser/parser.c parser/parser.h)
