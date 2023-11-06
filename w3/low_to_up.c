%{
#include <stdio.h>
int yyinput(char* buf, int max_size);
void yyunput(int c, char* buf);
%}

%%
[a-z] {
    char buffer[2];
    buffer[0] = yytext[0] - 32; // Convert to uppercase
    buffer[1] = '\0';
    yyunput(buffer[0], buffer);
}
.     { putchar(yytext[0]); }
%%

int main() {
    char input_buffer[1024];
    int num_chars;

    while ((num_chars = yyinput(input_buffer, sizeof(input_buffer))) > 0) {
        YY_BUFFER_STATE state = yy_scan_buffer(input_buffer, num_chars);
        yylex();
        yy_delete_buffer(state);
    }

    return 0;
}

int yyinput(char* buf, int max_size) {
    int i;
    for (i = 0; i < max_size; i++) {
        int c = getchar();
        if (c == EOF) {
            buf[i] = '\0';
            return i;
        }
        buf[i] = c;
    }
    return max_size;
}

void yyunput(int c, char* buf) {
    ungetc(c, stdin);
}

