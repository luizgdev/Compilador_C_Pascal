#ifndef COMPILADOR_C_PASCAL_TOKEN_DEF_H
#define COMPILADOR_C_PASCAL_TOKEN_DEF_H

// Definição dos tokens
typedef enum {
    TOK_EOF,
    TOK_KEYWORD,
    TOK_IDENTIFIER,
    TOK_OP, // provisório
    TOK_NUM, // provisório
    TOK_PONT, //provisório
    TOK_LITERAL, //provisório
    TOK_INTEGER,
    TOK_REAL,
    TOK_OP_ADD,
    TOK_OP_SUB,
    TOK_OP_MUL,
    TOK_OP_DIV,
    TOK_LPAREN,
    TOK_RPAREN,
    TOKEN_ASSIGN,
    TOK_SEMICOLON
} TokenType;

// Definição do struct para o token
typedef struct TokenDef {
    char *token;
    int token_type;
    struct TokenDef *next;
} Token;


#endif //COMPILADOR_C_PASCAL_TOKEN_DEF_H
