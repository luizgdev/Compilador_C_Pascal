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

void clear_token(char *);

// Função que verifica se um caractere é um espaço em branco
int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Função que verifica se um caractere é um dígito
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Função que verifica se um caractere é uma letra
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Função que verifica se é um literal
int is_literal(char c) {
    return c == '\'' || c == '\"';
}

// Função que verifica se uma string é uma palavra-chave
int is_keyword(char *token) {
    return !strcmp(token, "program") ||
           !strcmp(token, "var") ||
           !strcmp(token, "div") ||
           !strcmp(token, "writeln") ||
           !strcmp(token, "not") ||
           !strcmp(token, "begin") ||
           !strcmp(token, "end") ||
           !strcmp(token, "if") ||
           !strcmp(token, "then") ||
           !strcmp(token, "else") ||
           !strcmp(token, "while") ||
           !strcmp(token, "do") ||
           !strcmp(token, "repeat") ||
           !strcmp(token, "until") ||
           !strcmp(token, "for") ||
           !strcmp(token, "to") ||
           !strcmp(token, "downto") ||
           !strcmp(token, "function") ||
           !strcmp(token, "procedure") ||
           !strcmp(token, "integer") ||
           !strcmp(token, "real") ||
           !strcmp(token, "boolean") ||
           !strcmp(token, "char") ||
           !strcmp(token, "string");
}

// Função que verifica se um caractere é um operador
int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' ||
           c == '=' || c == '<' || c == '>' || c == ':' ||
           c == '.' || c == '[' || c == ']' || c == '^';
}

// Função que lê um token do arquivo e retorna seu tipo
int get_token(FILE *file, char *token) {
    int token_type = -1;
    int token_length = 0;
    char c = fgetc(file);

    // Descarta espaços em branco
    while (is_space(c)) {
        c = fgetc(file);
    }

// Verifica se é um número
    if (is_digit(c)) {
        token_type = 5; // número inteiro ou real
        while (is_digit(c)) {
            token[token_length++] = c;
            c = fgetc(file);
        }
        if (c == '.') { // número real
            token[token_length++] = c;
            c = fgetc(file);
            while (is_digit(c)) {
                token[token_length++] = c;
                c = fgetc(file);
            }
            token_type = 5; // número real
        } else {
            ungetc(c, file);
        }
    }

// Verifica se é uma palavra-chave, um identificador ou literal
    else if (is_letter(c) || is_literal(c)) {
        if (is_literal(c)) {
            while (is_letter(c) || is_digit(c) || c == '_' || is_literal(c) || is_space(c) || is_operator(c)) {
                token[token_length++] = c;
                c = fgetc(file);
            }
        } else {
            while (is_letter(c) || is_digit(c) || c == '_' || is_literal(c)) {
                token[token_length++] = c;
                c = fgetc(file);
            }
        }

        ungetc(c, file);

        if (is_keyword(token)) {
            token_type = 2; // palavra-chave
        } else if (is_literal(token[0])) {
            int i = 0;
            c = token[i];
            do {
                token[i++] = c++;
            } while (is_literal(c));
            token_type = 7; // literal
        } else {
            token_type = 3; // identificador
        }
    }

// Verifica se é um operador
    else if (is_operator(c)) {
        token[token_length++] = c;
        c = fgetc(file);
        if (c == '=') { // operadores compostos: <=, >=, <>, :=
            token[token_length++] = c;
            c = fgetc(file);
            if (c == '>' || c == '<' || c == '=') {
                token[token_length++] = c;
            } else {
                ungetc(c, file);
            }
        } else {
            ungetc(c, file);
        }
        token_type = 4; // operador
    }

// Verifica se é um símbolo de pontuação
    else if (c == ':' || c == '.' || c == ',' || c == ';' ||
             c == '(' || c == ')' || c == '[' || c == ']' || c == '^') {
        token[token_length++] = c;
        token_type = 6; // símbolo de pontuação
    }

// Retorna o tipo de token encontrado
    return token_type;
}

// Limpa restos de string no token
void clear_token(char *token) {
    int i = 0;
    while (token[i + 1] != '\0') {
        token[i] = '\0';
        i++;
    }
}

int main() {
    FILE *file;
    char filename[100];
    char token[100];
    int token_type;

    strcpy(filename, "/home/luiz/CLionProjects/analisadorLexico/teste.pas");

    // Abre o arquivo em modo de leitura
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê e imprime os tokens encontrados no arquivo
    while ((token_type = get_token(file, token)) != 0) {
        switch (token_type) {
            case 2:
                printf("Palavra-chave: %s\n", token);
                break;
            case 3:
                printf("Identificador: %s\n", token);
                break;
            case 4:
                printf("Operador: %s\n", token);
                break;
            case 5:
                printf("Número: %s\n", token);
                break;
            case 6:
                printf("Símbolo de pontuação: %s\n", token);
                break;
            case 7:
                printf("Literal: %s\n", token);
                break;
            default:
                break;
        }
        clear_token(token);
    }

    // Fecha o arquivo
    fclose(file);

    return 0;
}
