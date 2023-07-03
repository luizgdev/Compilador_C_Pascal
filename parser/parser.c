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
    var(currentToken->next->next->next);
}

void var(Token *currentToken) {
    if (strcmp(currentToken->token, "var")) {
        //error
    } else {
        while (strcmp(currentToken->next->token, "begin")) {
            if (varName(currentToken->next->token)) {
                //error
            } else if (strcmp(currentToken->next->next->token, ":")) {
                //error
            } else if (strcmp(currentToken->next->next->next->token, "integer") ||
                       strcmp(currentToken->next->next->next->token, "real") ||
                       strcmp(currentToken->next->next->next->token, "boolean") ||
                       strcmp(currentToken->next->next->next->token, "char") ||
                       strcmp(currentToken->next->next->next->token, "string") ||
                       strcmp(currentToken->next->next->next->token, "array")) {
                //error
            }
            currentToken = currentToken->next->next->next->next;
        }
    }
    codeBlock(currentToken->next);
}

void codeBlock(Token *currentToken) {
    Token *aux = currentToken;

    if (strcmp(aux->token, "begin")) {
        //error
    }
    while (strcmp(aux->token, "end") && strcmp(aux->token, ".")) {
        if (aux->next == NULL) {
            //error
        }
        aux = aux->next;
    }
    statement(currentToken->next);
}

void statement(Token *currentToken) {
    Token *aux = currentToken;

    // Implemente aqui a lógica para a regra do statement
    if (!strcmp(currentToken->token, "write") ||
        !strcmp(currentToken->token, "writeln")) {
        if (strcmp(currentToken->next->token, "(")) {
            //error
        }
        while (strcmp(aux->token, ")")) {
            if (aux->next == NULL) {
                //error
            }
            aux = aux->next;
        }
        if (strcmp(currentToken->next->token, ";")) {
            //error
        }
    }
    currentToken = aux->next->next;
    if (!strcmp(currentToken->token, "read") ||
        !strcmp(currentToken->token, "readln")) {
        if (strcmp(currentToken->next->token, "(")) {
            //error
        } else if (strcmp(currentToken->next->next->token, ")")) {
            //error
        } else if (strcmp(currentToken->next->next->next->token, ";")) {
            //error
        }
    }
    currentToken = currentToken->next->next->next->next->next;
    if (!strcmp(currentToken->token, "if")) {
        if (!(currentToken->next->token_type == TOK_IDENTIFIER ||
              currentToken->next->token_type == TOK_NUM)) {
            //error
        } else if (currentToken->next->next->token_type != TOK_OP) {
            //error
        } else if (!(currentToken->next->next->next->token_type == TOK_IDENTIFIER ||
                     currentToken->next->next->next->token_type == TOK_NUM)) {
            //error
        }
    }
    currentToken = currentToken->next->next->next->next->next;
    if (!strcmp(currentToken->token, "begin")) {
        aux = currentToken;
        while ((strcmp(aux->token, "end") && strcmp(aux->token, ";")) || strcmp(aux->token, "end")) {
            if (aux->next == NULL) {
                //error
            }
            aux = aux->next;
        }
    }
//    expression();
}

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
        while (*str++ != '\0') {
            if (!(isalpha(*str) || isdigit(*str) || *str == '_')) {
                //error
            }
        }
    }
    return 1;
}

int varName(char *str) {
    if (!isalpha(str[0])) {
        //error
    } else {
        // Checa o resto dos caracteres
        while (*str++ != '\0') {
            if (!(isalpha(*str) || isdigit(*str) || *str == '_')) {
                //error
            }
        }
    }
    return 1;
}
