#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TABLE_SIZE 1000

struct Symbol {
    int state;
    char name[20];
    char code[20];
    char type[20];
    int value;
};

struct HashTable {
    struct Symbol *table[MAX_TABLE_SIZE];
};

int hash(char *key) {
    int hashVal = 0;
    while (*key != '\0') {
        hashVal = (hashVal << 5) + *key++;
    }
    return hashVal % MAX_TABLE_SIZE;
}

struct Symbol* createSymbol(char *name, int value) {
    struct Symbol* symbol = (struct Symbol*) malloc(sizeof(struct Symbol));
    strncpy(symbol->name, name, 20);
    strncpy(symbol->name, name, 20);
    strncpy(symbol->name, name, 20);
    symbol->value = value;
    symbol->state = state;
    return symbol;
}

void insert(struct HashTable* ht, char *name, int value) {
    int index = hash(name);
    struct Symbol* symbol = createSymbol(name, value);
    while (ht->table[index] != NULL) {
        index = (index + 1) % MAX_TABLE_SIZE;
    }
    ht->table[index] = symbol;
}

struct Symbol* search(struct HashTable* ht, char *name) {
    int index = hash(name);
    while (ht->table[index] != NULL) {
        if (strcmp(ht->table[index]->name, name) == 0) {
            return ht->table[index];
        }
        index = (index + 1) % MAX_TABLE_SIZE;
    }
    return NULL;
}

int main() {
    struct HashTable ht;
    memset(ht.table, 0, sizeof(ht.table));

    insert(&ht, "x", 5);
    insert(&ht, "y", 10);
    insert(&ht, "z", 15);

    struct Symbol* s1 = search(&ht, "x");
    struct Symbol* s2 = search(&ht, "y");
    struct Symbol* s3 = search(&ht, "z");

    printf("%s: %d\n", s1->name, s1->value);
    printf("%s: %d\n", s2->name, s2->value);
    printf("%s: %d\n", s3->name, s3->value);

    return 0;
}
