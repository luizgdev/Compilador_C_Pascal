#include "parser.h"

void program(Token *currentToken) {
    // Lógica do program
    if (strcmp(currentToken->token, "program")) {
        error_1(); // program escrito errado ou faltando.
    } else if (programName(currentToken->next->token)) {
        error_2(); // nome do programa escrito errado.
    } else if (strcmp(currentToken->next->next->token, ";")) {
        error_3(1); // faltando o ;
    }
    var(currentToken->next->next->next);
}

void var(Token *currentToken) {
    if (strcmp(currentToken->token, "var")) {
        error_4(); // faltando o var
    } else if (varName(currentToken->next->token)) {
        error_5(4); // nome de variavel errado
    } else if (strcmp(currentToken->next->next->token, ":")) {
        error_6(4); // faltando o ":"
    } else if (strcmp(currentToken->next->next->next->token, "integer") &&
               strcmp(currentToken->next->next->next->token, "real") &&
               strcmp(currentToken->next->next->next->token, "boolean") &&
               strcmp(currentToken->next->next->next->token, "char") &&
               strcmp(currentToken->next->next->next->token, "string") &&
               strcmp(currentToken->next->next->next->token, "array")) {
        error_7(4); // erro de tipo
    } else if(strcmp(currentToken->next->next->next->next->token, ";")){
        error_3(4); // faltando o ;
    }
    currentToken = currentToken->next->next->next->next->next;
    if (varName(currentToken->next->token)) {
        error_5(5); // nome de variavel errado
    } else if (strcmp(currentToken->next->next->token, ":")) {
        error_6(5); // faltando o ":"
    } else if (strcmp(currentToken->next->next->next->token, "integer") &&
               strcmp(currentToken->next->next->next->token, "real") &&
               strcmp(currentToken->next->next->next->token, "boolean") &&
               strcmp(currentToken->next->next->next->token, "char") &&
               strcmp(currentToken->next->next->next->token, "string") &&
               strcmp(currentToken->next->next->next->token, "array")) {
        error_7(5); // erro de tipo
    } else if(strcmp(currentToken->next->next->next->next->token, ";")){
        error_3(5); // faltando o ;
    }
    codeBlock(currentToken->next);
}

void codeBlock(Token *currentToken) {
    Token *aux = currentToken;

    if (strcmp(aux->token, "begin")) {
        error_8(7); // Faltando begin
    }
    while (strcmp(aux->token, "end") && strcmp(aux->token, ".")) {
        if (aux->next == NULL) {
            error_9(20); // Begin sem End
        }
        aux = aux->next;
    }
    statement(currentToken->next);
}

void statement(Token *currentToken) {
    Token *aux = currentToken;

    // Implemente aqui a lógica para a regra do statement
    if (!strcmp(currentToken->token, "write")) {
        if (strcmp(currentToken->next->token, "(")) {
            error_11(8);  // faltando (
        }
        while (strcmp(aux->token, ")")) {
            if (aux->next == NULL) {
                error_12(8); // faltando o )
            }
            aux = aux->next;
        }
        if (strcmp(currentToken->next->token, ";")) {
            error_3(8); // faltando o ;
        }
    }
    else{
            error_10(8); // write escrito
    }
    currentToken = aux->next->next;
    if (!strcmp(currentToken->token, "read")) {
        if (strcmp(currentToken->next->token, "(")) {
            //error
        } else if (strcmp(currentToken->next->next->token, ")")) {
            //error
        } else if (strcmp(currentToken->next->next->next->token, ";")) {
            //error
        }
    } else {
        error_13(); // read escrito errado
    }
    currentToken = currentToken->next->next->next->next->next;
    if (!strcmp(currentToken->token, "if")) {
        if (currentToken->next->token_type != TOK_IDENTIFIER &&
            currentToken->next->token_type != TOK_NUM) {
            //error
        } else if (currentToken->next->next->token_type != TOK_OP) {
            //error
        } else if (currentToken->next->next->next->token_type != TOK_IDENTIFIER &&
                   currentToken->next->next->next->token_type != TOK_NUM) {
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
    expression(currentToken->next);
    currentToken = currentToken->next->next->next->next->next->next->next;
    if (!strcmp(currentToken->token, "write") ||
        !strcmp(currentToken->token, "writeln")) {
        aux = currentToken;
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
    currentToken = currentToken->next->next->next->next->next->next->next->next->next;
    if (!strcmp(currentToken->token, "begin")) {
        aux = currentToken;
        while ((strcmp(aux->token, "end") && strcmp(aux->token, ";")) || strcmp(aux->token, "end")) {
            if (aux->next == NULL) {
                //error
            }
            aux = aux->next;
        }
    }
    currentToken = currentToken->next;
    if (!strcmp(currentToken->token, "write") ||
        !strcmp(currentToken->token, "writeln")) {
        aux = currentToken;
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
}

void expression(Token *currentToken) {
    //
    if (currentToken->token_type != TOK_IDENTIFIER) {
        //error
    } else if (strcmp(currentToken->next->token, ":=")) {
        // error
    } else if (currentToken->next->next->token_type != TOK_IDENTIFIER &&
               currentToken->next->next->token_type != TOK_NUM) {
        printf("hjkgjh\n");
        //error
    } else if (currentToken->next->next->next->token_type != TOK_OP) {
        //error
    } else if (currentToken->next->next->next->next->token_type != TOK_IDENTIFIER &&
               currentToken->next->next->next->next->token_type != TOK_NUM) {
        //error
    } else if (strcmp(currentToken->next->next->next->next->next->token, ";")) {
        //error
    }
}

int programName(char *str) {
    // Checa se o primeiro caractere é um digito
    if (isdigit(str[0])) {
        return 1;
    } else {
        // Checa o resto dos caracteres
        while (*str++ != '\0') {
            if (!(isalpha(*str) || isdigit(*str) || *str == '_' || *str == '\0')) {
                return 1;
            }
        }
    }
    return 0;
}

int varName(char *str) {
    if (!isalpha(str[0])) {
        return 1;
    } else {
        // Checa o resto dos caracteres
        while (*str++ != '\0') {
            if (!(isalpha(*str) || isdigit(*str) || *str == '_' || *str == '\0')) {
                return 1;
            }
        }
    }
    return 0;
}
