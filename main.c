
#include "lexer/lexer.h"

int main() {
    FILE *file;
    char filename[100];
    char token[100];
    int token_type;

    strcpy(filename, "/home/luiz/CLionProjects/C_Pascal_Compiler/teste.pas");

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
