#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RESULT 100
#define COL 8
#define ROW 8
#define TRUE 1
#define FALSE 0

int queen_result[MAX_RESULT][COL];
int patterns_count = 0;

int can_place_queen(int const, int const,int [COL]);
void place_queen(int const, int [COL]);
void find_patterns(void);
void handle_a_result(int [COL]);
void print_pattern(int [COL]);

int main()
{
    clock_t start, ends;
    start = clock();

    find_patterns();

    printf("\r\n Count is: %d\r\n", patterns_count);

    ends = clock();

    printf("\r\n%d\r\n", ends - start);
    return 0;
}

void find_patterns(void)
{
    int queen_row_arr[COL];
    place_queen(0, queen_row_arr);
}

void place_queen(int const queen_row, int queen_row_arr[COL])
{
    if(queen_row >= ROW)
    {
        handle_a_result(queen_row_arr);
        return;
    }

    int col;

    for(col = 0; col < COL; col++)
    {
        if(can_place_queen(queen_row, col, queen_row_arr) == TRUE)
        {
            queen_row_arr[queen_row] = col;
            place_queen(queen_row + 1, queen_row_arr);
        }
        else
        {
            continue;
        }
    }
}

int can_place_queen(int const queen_row, int const queen_col, int queen_row_arr[COL])
{
    if(queen_row == 0)
        return TRUE;

    int row;
    for(row = 0; row < queen_row; row++)
    {
        if(queen_row_arr[row] == queen_col)
            return FALSE;

        if(abs(row - queen_row) == abs(queen_col - queen_row_arr[row]))
            return FALSE;
    }

    return TRUE;
}

void handle_a_result(int queen_row_arr[COL])
{
    print_pattern(queen_row_arr);

    int *index, *tmp;
    for(index = *queen_result + patterns_count, tmp = queen_row_arr; tmp < &queen_row_arr[COL];)
    {
        *index++ = *tmp++;
    }

    patterns_count++;
}

void print_pattern(int queen_row_arr[COL])
{
    int i, j;
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            if(j == queen_row_arr[i])
                printf("o");
            else
                printf("+");
        }
        printf("\r\n");
    }
    printf("\r\n");
}
