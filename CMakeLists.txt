cmake_minimum_required(VERSION 3.25)
project(Compilador_C_Pascal C)

set(CMAKE_C_STANDARD 11)

add_executable(Compilador_C_Pascal main.c tests/test_lexer.pas tests/test_lexer_2.pas lexer/lexer.c lexer/lexer.h parser/parser.c parser/parser.h utils/symbol_table/symbol_table.c utils/symbol_table/symbol_table.h utils/symbol_table/symbol_table.c utils/token_def/token_def.h)
