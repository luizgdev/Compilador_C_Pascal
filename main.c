#include "lexer/lexer.h" // Inclui o analisador léxico
#include "utils/symbol_table/symbol_table.h" // Inclui a tabela de símbolos
//#include "parser/parser.h" // Inclui o analisador sintático

int main() {
    FILE *file;
    char filename[100];
    char token[100];
    clear_token(token);
    int token_type;

    // Cria a tabela hash
    //HashTable *hashTable = createHashTable();

    // Cria a tabela de símbolos
    SymbolTable **sTable = createSymbolTable();

    // Pega o nome do arquivo
    strcpy(filename, "/home/luiz/CLionProjects/C_Pascal_Compiler/tests/test_lexer_2.pas");

    // Abre o arquivo em modo de leitura
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê e imprime os tokens encontrados no arquivo
    while ((token_type = get_token(file, token)) !=0) {
        switch (token_type) {
            case 1:
                printf("Palavra-chave: %s\n", token);
                break;
            case 2:
                printf("Identificador: %s\n", token);
                break;
            case 3:
                printf("Operador: %s\n", token);
                break;
            case 4:
                printf("Número: %s\n", token);
                break;
            case 5:
                printf("Símbolo de pontuação: %s\n", token);
                break;
            case 6:
                printf("Literal: %s\n", token);
                break;
            default:
                break;
        }
        addSymbol(sTable, token, token_type);
        clear_token(token);
    }

    // Fecha o arquivo
    fclose(file);

    // Imprime a tabela
    printTable((*sTable)->table);

//    // Obtém o primeiro token
//    currentToken = getNextToken();
//
//    // Chama a função de análise sintática para o programa
//    program();
//
//    // Verifica se chegou ao final do arquivo
//    match(TOK_EOF);
//
//    printf("Análise sintática concluída com sucesso!\n");

    // Libera a memória utilizada pela tabela hash
    //freeHashTable(hashTable);

    return 0;
}
