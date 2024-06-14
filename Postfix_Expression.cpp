#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top < MAX - 1) {
        stack[++top] = x;
    }
}

int pop() {
    if (top != -1) {
        return stack[top--];
    }
    return -1;
}

int evaluatePostfix(char* exp) {
    char* e = exp;
    int n1, n2, n3, num;
    while (*e != '\0') {
        if (isdigit(*e)) {
            num = *e - '0';
            push(num);
        } else {
            n1 = pop();
            n2 = pop();
            switch (*e) {
                case '+': n3 = n2 + n1; break;
                case '-': n3 = n2 - n1; break;
                case '*': n3 = n2 * n1; break;
                case '/': n3 = n2 / n1; break;
            }
            push(n3);
        }
        e++;
    }
    return pop();
}

int main() {
    char exp[MAX];
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    printf("Result of postfix expression: %d\n", evaluatePostfix(exp));
    return 0;
}

