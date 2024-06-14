#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("%d ", hashTable[i]);
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
   

