#include <stdio.h>
#include <string.h>
#include <time.h>

int main()
{
    char messages[100] = "Hello World!!!!!!!!!!!!!!!!!!!!!!!!!";

    printf("%s", messages);

    char str[10];

    strncpy(str, messages, strlen(messages));

    printf("\t%c", str[110]);
}
