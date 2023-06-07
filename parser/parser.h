#ifndef C_PASCAL_COMPILER_PARSER_H
#define C_PASCAL_COMPILER_PARSER_H

#include <stdio.h>
#include <stdlib.h>

// Definição dos tokens
typedef enum {
    TOK_INTEGER,
    TOK_REAL,
    TOK_IDENTIFIER,
    TOK_OP_ADD,
    TOK_OP_SUB,
    TOK_OP_MUL,
    TOK_OP_DIV,
    TOK_LPAREN,
    TOK_RPAREN,
    TOKEN_ASSIGN,
    TOK_SEMICOLON,
    TOK_EOF
} TokenType;

// Estrutura de um token
typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

// Protótipos das funções
Token getNextToken();

void match(TokenType expectedToken);

void program();

void statement();

void expression();

void term();

void factor();

// Variável global para armazenar o token atual
Token currentToken;

#endif //C_PASCAL_COMPILER_PARSER_H
