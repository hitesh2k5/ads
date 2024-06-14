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
    int i = 1;
    while (hashTable[index] != -1) {
        index = (index + i * i) % TABLE_SIZE;
        i++;
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
    initializeTable();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    printf("Hash Table: ");
    display();
    return 0;
}

