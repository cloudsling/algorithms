#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10000000
#define NUM_COUNT 1000000
#define TRUE 1
#define FALSE 0

#define store_bit(num) (bit_vector[num]=1)

int bit_vector[LEN];
FILE *output;

int is_stored(int);

void generate_output(char **);

int rand_num();

int main(char *argc, char *argv[]) {
    srand(time(NULL));
    if (*argv == NULL)
        exit(EXIT_FAILURE);

    generate_output(argv);

    return 0;
}

void generate_output(char **argv) {

    int i;
    output = fopen(*argv, "w");

    if (output == NULL){
        perror("No such file");
        exit(EXIT_FAILURE);
    }


    for (i = 0; i < NUM_COUNT;) {
        int res = rand_num();

        if (is_stored(res) == FALSE) {

            store_bit(res);
            fprintf(output, "%.7d\n", res);
            ++i;
        }
    }
    if (fclose(output) != 0)
        exit(EXIT_FAILURE);
}

int is_stored(int num) {

    return (1 == bit_vector[num]) ? TRUE : FALSE;
}

int rand_num() {
    return rand() % LEN;
}
