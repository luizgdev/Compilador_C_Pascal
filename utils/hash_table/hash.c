#include "hash.h"

unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // djb2 hash function
    }

    return hash % HASH_SIZE;
}

HashTable *createHashTable() {
    HashTable *hashTable = (HashTable *) malloc(sizeof(HashTable));

    if (hashTable == NULL) {
        printf("ERRO NA CRIAÇÃO DA TABELA.\n");
        exit(1);
    }
    hashTable->table = (HashEntry **) malloc(HASH_SIZE * sizeof(HashEntry *));
    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable->table[i] = NULL;
    }

    return hashTable;
}

HashEntry *createHashEntry() {
    HashEntry *entry = (HashEntry *) malloc(sizeof(HashEntry));

    if (entry == NULL) {
        printf("ERRO NA CRIAÇÃO DA ENTRY.\n");
        exit(1);
    } else {
        entry->token_type = 0;
        entry->token = NULL;
        entry->next = NULL;
    }
    return entry;
}

void insertToken(HashTable *hashTable, const char *token, int token_type) {
    unsigned long index = hash(token);
    HashEntry *entry = createHashEntry();
    entry->token = strdup(token);
    entry->token_type = token_type;

    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = entry;
    } else {
        HashEntry *current = hashTable->table[index];

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = entry;
    }
}

HashEntry *findToken(HashTable *hashTable, const char *token) {
    unsigned long index = hash(token);
    HashEntry *current = hashTable->table[index];

    while (current != NULL) {
        if (strcmp(current->token, token) == 0) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void printHashTable(HashTable* hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        HashEntry *current = hashTable->table[i];
        printf("[%d]: ", i);
        if (current != NULL) {
            printf("(%s, %d)", current->token, current->token_type);
        }
        printf("\n");
    }
}

void freeHashTable(HashTable *hashTable) {
    int i = 0;
    for (i = 0; i < HASH_SIZE; i++) {
        HashEntry *current = hashTable->table[i];
        while (current != NULL) {
            HashEntry *next = current->next;
            free(current->token);
            free(current);
            current = next;
        }
    }

    free(hashTable->table);
    free(hashTable);
}
