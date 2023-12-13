#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STRING_MAX_SIZE 100

typedef struct {
        char *ptr;
        int size;
        int top;
}stack;

void createStack(stack *stk) {
        stk->ptr = (char *) malloc(stk->size * sizeof(char));
        stk->top = -1;
}

void push(stack *stk, char letter){
        stk->ptr[++stk->top] = letter;
}

char pop(stack *stk){
        return stk->ptr[stk->top--];
}

int getLength(char str[]){
        return strlen(str);
}

int checkPalindrome(char str[]) {
        stack stk;
        stk.size = getLength(str);
        createStack(&stk);
        for(int i = 0 ; i < stk.size ; i++) {
                push(&stk, str[i]);
        }
        char *rev = malloc(stk.size + 1);
        for(int i = 0 ; i < stk.size  ; i++) {
                rev[i] = pop(&stk);
        }
        rev[stk.size] = '\0';
        if(strcmp(str,rev) == 0)
                return 1;
        return 0;
}

void main() {
        char str[STRING_MAX_SIZE];
        printf("\n Enter a string: ");
        scanf("%s", &str);
        if ( checkPalindrome(str) ) {
                printf("\n The Entered String (%s) is a palindrome",str);
        } else {
                printf("\n The Entered String (%s) is not a palindrome",str);
        }
}