#ifndef C_PASCAL_COMPILER_PARSER_H
#define C_PASCAL_COMPILER_PARSER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../utils/token_def/token_def.h"

// Apelido para Node
typedef struct TokenDef Token;

// Protótipos das funções
Token getNextToken(struct TokenDef *);

void match(Token *, TokenType );

void program(Token *);

void statement();

void expression();

void term();

void factor();

int programName(char *);

#endif //C_PASCAL_COMPILER_PARSER_H
