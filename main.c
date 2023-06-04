#include "lexer/lexer.h" // Inclui o analisador léxico
#include "utils/hash_table/hash.h" // Inclui a tabela hash

int main() {
    FILE *file;
    char filename[100];
    char token[100];
    clear_token(token);
    int token_type;

    // Cria a tabela hash
    HashTable *hashTable = createHashTable();

    strcpy(filename, "/home/luiz/CLionProjects/C_Pascal_Compiler/tests/test_lexer.pas");

    // Abre o arquivo em modo de leitura
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê e imprime os tokens encontrados no arquivo
    while ((token_type = get_token(file, token)) != 1) {
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
        insertToken(hashTable, token, token_type);
        clear_token(token);
    }

    // Fecha o arquivo
    fclose(file);

    // Imprime a tabela
    printHashTable(hashTable);

    // Libera a mem�ria utilizada pela tabela hash
    freeHashTable(hashTable);

    return 0;
}
