#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node* next;
};

void insert(struct Node** poly, int coeff, int pow) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = NULL;

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->pow > poly2->pow) {
            insert(&result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            insert(&result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            insert(&result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insert(&result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insert(&result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* polySum = NULL;

    insert(&poly1, 5, 2);
    insert(&poly1, 4, 1);
    insert(&poly1, 2, 0);

    insert(&poly2, 5, 1);
    insert(&poly2, 5, 0);

    printf("Polynomial 1: ");
    display(poly1);
    printf("\n");

    printf("Polynomial 2: ");
    display(poly2);
    printf("\n");

    polySum = addPolynomials(poly1, poly2);

    printf("Sum of Polynomials: ");
    display(polySum);
    printf("\n");

    return 0;
}

