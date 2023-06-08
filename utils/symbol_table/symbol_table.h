#ifndef C_PASCAL_COMPILER_SYMBOL_TABLE_H
#define C_PASCAL_COMPILER_SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SymbolNode {
    char *token;
    int token_type;
    struct SymbolNode *next;
} Node;

typedef struct {
    Node *table;
} SymbolTable;

SymbolTable **createSymbolTable();

void addSymbol(SymbolTable **, char *, int);

void printTable(Node *);

void freeTable(Node *);

#endif //C_PASCAL_COMPILER_SYMBOL_TABLE_H
