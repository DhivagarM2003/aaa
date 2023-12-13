#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int precedence(char operator) {
    if (operator == '^')
        return 3;
    else if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char* infix, char* postfix) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;
    stack[++top] = '(';
    strcat(infix, ")");

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            stack[++top] = '(';
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = stack[top--];
            top--; // Remove '(' from stack
        } else {
            while (precedence(infix[i]) <= precedence(stack[top]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }
    postfix[j] = '\0';
}

void reverseString(char* str) {
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char* infix, char* prefix) {
    char reversedInfix[MAX_SIZE], postfix[MAX_SIZE];
    int i;

    reverseString(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            reversedInfix[i] = ')';
        else if (infix[i] == ')')
            reversedInfix[i] = '(';
        else
            reversedInfix[i] = infix[i];
    }
    reversedInfix[i] = '\0';

    infixToPostfix(reversedInfix, postfix);
    reverseString(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}