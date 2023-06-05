#include "parser.h"

Token getNextToken() {
    // Implemente aqui a lógica para obter o próximo token da tabela hash
    // e retorne o token encontrado
}

void match(TokenType expectedToken) {
    // Verifica se o tipo do token atual coincide com o tipo esperado
    if (currentToken.type == expectedToken) {
        // Obtém o próximo token
        currentToken = getNextToken();
    } else {
        printf("Erro de sintaxe: token inesperado '%s'\n", currentToken.lexeme);
        exit(1);
    }
}

void program() {
    // Implemente aqui a lógica para a regra do programa
    statement();
}

void statement() {
    // Implemente aqui a lógica para a regra do statement
    expression();
}

void expression() {
    // Implemente aqui a lógica para a regra da expressão
    term();
    while (currentToken.type == TOK_OP_ADD || currentToken.type == TOK_OP_SUB) {
        match(currentToken.type);
        term();
    }
}

void term() {
    // Implemente aqui a lógica para a regra do termo
    factor();
    while (currentToken.type == TOK_OP_MUL || currentToken.type == TOK_OP_DIV) {
        match(currentToken.type);
        factor();
    }
}

void factor() {
    // Implemente aqui a lógica para a regra do fator
    if (currentToken.type == TOK_INTEGER|| currentToken.type == TOK_REAL || currentToken.type == TOK_IDENTIFIER) {
        match(currentToken.type);
    } else if (currentToken.type == TOK_LPAREN) {
        match(TOK_LPAREN);
        expression();
        match(TOK_RPAREN);
    } else {
        printf("Erro de sintaxe: token inesperado '%s'\n", currentToken.lexeme);
        exit(1);
    }
}
