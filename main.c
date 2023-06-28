#include "lexer/lexer.h" // Inclui o analisador léxico
#include "utils/symbol_table/symbol_table.h" // Inclui a tabela de símbolos
#include "parser/parser.h" // Inclui o analisador sintático
#include "utils/token_def/token_def.h" // Inclui a definição do TOKEN

int main() {
    FILE *file;
    char filename[100];
    char token[100];
    clear_token(token);
    TokenType token_type;

    // Cria a tabela de símbolos
    SymbolTable **sTable = createSymbolTable();

    // Pega o nome do arquivo
    strcpy(filename, "/home/luiz/Programação/GitHub/Compilador_C_Pascal/tests/test_lexer_2.pas");

    // Abre o arquivo em modo de leitura
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê e imprime os tokens encontrados no arquivo
    while ((token_type = get_token(file, token)) != TOK_EOF) {
        switch (token_type) {
            case TOK_KEYWORD:
                printf("Palavra-chave: %s\n", token);
                break;
            case TOK_IDENTIFIER:
                printf("Identificador: %s\n", token);
                break;
            case TOK_OP:
                printf("Operador: %s\n", token);
                break;
            case TOK_NUM:
                printf("Número: %s\n", token);
                break;
            case TOK_PONT:
                printf("Símbolo de pontuação: %s\n", token);
                break;
            case TOK_LITERAL:
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

    // Obtém o primeiro token
    Token *currentToken = (*sTable)->table;

    // Chama a função de análise sintática para o programa
    program(currentToken);

//    // Verifica se chegou ao final do arquivo
//    match(TOK_EOF);
//
//    printf("Análise sintática concluída com sucesso!\n");

    return 0;
}
