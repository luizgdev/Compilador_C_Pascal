#ifndef C_PASCAL_COMPILER_SYMBOL_TABLE_H
#define C_PASCAL_COMPILER_SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../token_def/token_def.h"

typedef Token Node;

typedef struct {
    Token *table;
} SymbolTable;

SymbolTable **createSymbolTable();

void addSymbol(SymbolTable **, char *, int);

void printTable(Token *);

void freeTable(Token *);

#endif //C_PASCAL_COMPILER_SYMBOL_TABLE_H
