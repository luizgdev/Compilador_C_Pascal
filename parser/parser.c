#include "parser.h"
#include "../utils/token_def/token_def.h"

//Token getNextToken(struct TokenDef *symbolTable) {
//    Token *tk
//    tk = symbolTable;
//    return *tk;
//}

void match(Token *currentToken, TokenType expectedToken) {
    // Verifica se o tipo do token atual coincide com o tipo esperado
    if (currentToken->token_type == expectedToken) {
        // Obtém o próximo token
        //currentToken = getNextToken();
    } else {
        printf("Erro de sintaxe: token inesperado '%s'\n", currentToken->token);
        exit(1);
    }
}

void program(Token *currentToken) {
    // Implemente aqui a lógica para a regra do programa
    if (strcmp(currentToken->token, "program")) {
        //error
    } else if (programName(currentToken->next->token)) {
        //error
    } else if (strcmp(currentToken->next->next->token, ";")) {
        //error
    }
    // statement();
}

//void statement() {
//    // Implemente aqui a lógica para a regra do statement
//    expression();
//}
//
//void expression() {
//    // Implemente aqui a lógica para a regra da expressão
//    term();
//    while (currentToken.type == TOK_OP_ADD || currentToken.type == TOK_OP_SUB) {
//        match(currentToken.type);
//        term();
//    }
//}
//
//void term() {
//    // Implemente aqui a lógica para a regra do termo
//    factor();
//    while (currentToken.type == TOK_OP_MUL || currentToken.type == TOK_OP_DIV) {
//        match(currentToken.type);
//        factor();
//    }
//}
//
//void factor() {
//    // Implemente aqui a lógica para a regra do fator
//    if (currentToken.type == TOK_INTEGER|| currentToken.type == TOK_REAL || currentToken.type == TOK_IDENTIFIER) {
//        match(currentToken.type);
//    } else if (currentToken.type == TOK_LPAREN) {
//        match(TOK_LPAREN);
//        expression();
//        match(TOK_RPAREN);
//    } else {
//        printf("Erro de sintaxe: token inesperado '%s'\n", currentToken.lexeme);
//        exit(1);
//    }
//}

int programName(char *str) {
    // Checa se o primeiro caractere é um digito
    if (isdigit(str[0])) {
        //error
    } else {
        // Checa o resto dos caracteres
        while (*str != '\0') {
            if (!(isalpha(*str) || isdigit(*str) || *str == '_')) {
                //error
            }
        }
    }
    return 1;
}
