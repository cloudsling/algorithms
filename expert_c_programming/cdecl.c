#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXTOKENLEN 100
#define MAXTOKENS 64

enum type_tag {
    QUALIFIER, INDENTIFIER, TYPE
};

struct token {
    char type;
    char string[MAXTOKENLEN];
};

struct token stack[MAXTOKENS];
struct token this_t;

int top = -1;

#define pop stack[top--]
#define push(TOKEN) (stack[++top]=(TOKEN))
#define STRCMP(STR1, STR2) (!strcmp((STR1), (STR2)))

enum type_tag classify_string();

void gettoken();

void read_to_first_identifier();

void deal_with_function_args();

void deal_with_arrays();

void deal_with_any_pointers();

void deal_with_declarator();

int main() {


    read_to_first_identifier();
    deal_with_declarator();
    printf("\n");

    return 0;
}

enum type_tag classify_string() {

    char *str = this_t.string;

    if (STRCMP(str, "const")) {
        strcpy(str, "read-only");
        return QUALIFIER;
    }
    if (STRCMP(str, "volatile")) return QUALIFIER;

    if (STRCMP(str, "int")) return TYPE;
    if (STRCMP(str, "char")) return TYPE;
    if (STRCMP(str, "void")) return TYPE;
    if (STRCMP(str, "unsigned")) return TYPE;
    if (STRCMP(str, "signed")) return TYPE;
    if (STRCMP(str, "short")) return TYPE;
    if (STRCMP(str, "float")) return TYPE;
    if (STRCMP(str, "double")) return TYPE;
    if (STRCMP(str, "struct")) return TYPE;
    if (STRCMP(str, "enum")) return TYPE;
    if (STRCMP(str, "union")) return TYPE;
    if (STRCMP(str, "long")) return TYPE;

    return INDENTIFIER;
}

void gettoken() {

    char *ch = this_t.string;
    while ((*ch = getchar()) == ' ');

    if (isalnum(*ch)) {

        while (isalnum(*++ch = getchar()));

        ungetc(*ch, stdin);
        *ch = '\0';

        this_t.type = classify_string();
        return;
    }

    if (*ch == '*') {
        strcpy(this_t.string, "pointer to");
        this_t.type = '*';
        return;
    }

    this_t.string[1] = '\0';
    this_t.type = *ch;
    return;
}

void read_to_first_identifier() {

    gettoken();

    while (this_t.type != INDENTIFIER) {
        push(this_t);
        gettoken();
    }
    printf("identifier is: %s ", this_t.string);
    gettoken();
}

void deal_with_function_args() {

    while (this_t.type != ')')
        gettoken();

    gettoken();
    printf("fuction returing ");
}

void deal_with_arrays() {

    while (this_t.type == '[') {

        printf("array ");
        gettoken();

        if (isdigit(this_t.string[0])) {
            printf("0..%d", atoi(this_t.string) - 1);
            gettoken();
        }

        gettoken();
        printf("of ");
    }
}

void deal_with_any_pointers() {

    while (stack[top].type == '*')
        printf("%s ", pop.string);
}

void deal_with_declarator() {

    switch (this_t.type) {
        case '\n':
            break;
        case '[':
            deal_with_arrays();
            break;
        case '(':
            deal_with_function_args();
            break;
    }

    deal_with_any_pointers();

    while (top >= 0) {

        if (stack[top].type == '(') {
            pop;
            gettoken();
            deal_with_declarator();
        } else {
            printf("%s ", pop.string);
        }
    }
}