#include "lexer.h"

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
// Função que verifica se chegou no final do arquivo
int is_eof(FILE *file) {
    int current_position = ftell(file);  // Obtém a posição atual do arquivo
    fseek(file, 0, SEEK_END);  // Move para o final do arquivo
    int end_position = ftell(file);  // Obtém a posição do final do arquivo
    fseek(file, current_position, SEEK_SET);  // Restaura a posição anterior
    return (current_position == end_position);  // Verifica se a posição atual é igual à do final
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

// Verifica se chegou no final do arquivo
    if (is_eof(file)) {
        token_type = 0;  // Final do arquivo
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
