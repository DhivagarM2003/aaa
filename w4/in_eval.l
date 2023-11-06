%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100];
char operator_stack[100];
int top = -1;
int operator_top = -1;

int get_precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int eval_operator(int op1, int op2, char operator) {
    switch (operator) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: return 0; // Handle other operators as needed
    }
}
%}

%%
[0-9]+      { stack[++top] = atoi(yytext); }
[-+*/]      {
                while (operator_top >= 0 && get_precedence(operator_stack[operator_top]) >= get_precedence(yytext[0])) {
                    int op2 = stack[top--];
                    int op1 = stack[top--];
                    stack[++top] = eval_operator(op1, op2, operator_stack[operator_top--]);
                }
                operator_stack[++operator_top] = yytext[0];
            }
\(          { operator_stack[++operator_top] = '('; }
\)          {
                while (operator_top >= 0 && operator_stack[operator_top] != '(') {
                    int op2 = stack[top--];
                    int op1 = stack[top--];
                    stack[++top] = eval_operator(op1, op2, operator_stack[operator_top--]);
                }
                if (operator_top >= 0 && operator_stack[operator_top] == '(') {
                    operator_top--;
                } else {
                    printf("Mismatched parentheses\n");
                    exit(1);
                }
            }
\n          {
                while (operator_top >= 0) {
                    int op2 = stack[top--];
                    int op1 = stack[top--];
                    stack[++top] = eval_operator(op1, op2, operator_stack[operator_top--]);
                }
                printf("Result: %d\n", stack[top]);
                top = -1;
            }
[ \t]       ; // Ignore whitespace
.           { printf("Invalid character: %s\n", yytext); }
%%

int main() {
    yylex();
    return 0;
}

