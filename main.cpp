//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//
//#define MAX_COLS 20
//#define MAX_INPUT 1000
//
//int read_column_numbers(int [], int);
//
//void rearrange(char *output, char const *input, int n_columns, int const columns[]);
//
//int main(void) {
//    int n_columns;
//    int columns[MAX_COLS];
//    int input[MAX_INPUT];
//    int output[MAX_INPUT];
//
//    n_columns = read_column_numbers(columns, MAX_COLS);
//
//    while(gets((char *) input) != NULL ){
//        printf("Original input is : %s \n", input);
//        rearrange(output, input, n_columns, columns);
//        printf("Rearranged line :  %s\n", output);
//    }
//
//}
//
//int read_column_numbers(int columns[], int max) {
//    int num = 0;
//    int ch  ;
//
//    while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
//        num += 1;
//
//    if (num % 2 != 0) {
//        puts("Last column number is not paired.");
//        exit(EXIT_FAILURE);
//    }
//
//    while ((ch = getchar()) != EOF && ch != '\n');
//
//    return 0;
//}
//
//void rearrange(char *output, char const *input, int n_column, int const columns[])
//{
//    int col;
//    int output_col;
//    int len;
//
//    len = strlen(input);
//    output_col = 0;
//
//    for ( col = 0; col < n_column; col += 2) {
//        int n;
//        n = columns[col + 1] - columns[col] - 1;
//
//        if(columns[col] > len || output_col == MAX_COLS -1)
//            break;
//
//        if(output_col +n > MAX_INPUT -1)
//            n = MAX_INPUT - output_col -1;
//
//    strncpy(output+output_col ,input + columns[col],n);
//    output_col+= n;
//    }
//
//    output[output_col] = '\0';
//}