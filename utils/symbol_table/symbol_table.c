#include "symbol_table.h"

// Função que cria a tabela de símbolos
SymbolTable **createSymbolTable() {
    SymbolTable **sTable = (SymbolTable **) malloc(sizeof(SymbolTable));
    (*sTable) = (SymbolTable *) malloc(sizeof(SymbolTable));

    if (sTable == NULL) {
        printf("ERRO NA CRIAÇÃO DA TABELA DE SÍMBOLOS.");
        exit(1);
    }

    return sTable;
}

// Função para adicionar um novo símbolo à tabela
void addSymbol(SymbolTable **sTable, char *token, int token_type) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->token = strdup(token);
    newNode->token_type = token_type;
    newNode->next = NULL;

    if ((*sTable)->table == NULL) {
        (*sTable)->table = newNode;
    } else {
        Node *current = (*sTable)->table;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Função para imprimir a tabela de símbolos
void printTable(Node *table) {
    printf("Tabela de símbolos:\n");
    Node *current = table;
    int i = 0;
    while (current != NULL) {
        printf("Slot %d: |%s, %d|\n", i++, current->token, current->token_type);
        current = current->next;
    }
}

// Função para liberar a memória alocada pela tabela de símbolos
void freeTable(Node *table) {
    Node *current = table;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}
