#ifndef C_PASCAL_COMPILER_HASH_H
#define C_PASCAL_COMPILER_HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 100

typedef struct he {
    char *token;
    int token_type;
    struct he *next;
} HashEntry;

typedef struct {
    HashEntry **table;
} HashTable;

unsigned long hash(const char *);

HashTable *createHashTable();

HashEntry *createHashEntry();

void insertToken(HashTable *, const char *, int);

HashEntry *findToken(HashTable *, const char *);

void printHashTable(HashTable *);

void freeHashTable(HashTable *);

#endif //C_PASCAL_COMPILER_HASH_H
