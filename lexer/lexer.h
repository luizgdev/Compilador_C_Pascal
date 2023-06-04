#ifndef C_PASCAL_COMPILER_LEXER_H
#define C_PASCAL_COMPILER_LEXER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_space(char);

int is_digit(char);

int is_letter(char);

int is_literal(char);

int is_keyword(char *);

int is_operator(char);

int get_token(FILE *, char *);

int is_eof(FILE *);

void clear_token(char *);

#endif //C_PASCAL_COMPILER_LEXER_H
