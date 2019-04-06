#include <stdio.h>

#define N 8
#define bool int
bool solveKT();
int SolveKTtil(int, int, int, char**);
void printSolution();

int horizontal[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int vertical[8] = {  2, 1, -1, -2, -2, -1,  1,  2};

int main(void)
{
    solveKT();
    printSolution();
}

bool solveKT()
{
    char b[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            b[i][j] = '0';
        }
    }
    int x, y;
    x = y = 0;
    if(SolveKTtil(x, y, 1, b)) printSolution(b);
    // int count = 0;
    // int currentRow, currentCol;
    // b[4][4] = 'K';
    // for(int pos=0; pos <8; pos++)
    // {
    //     currentRow = 4;
    //     currentCol = 4;
    //     currentRow += vertical[pos];
    //     currentCol += horizontal[pos];
    //     b[currentRow][currentCol] = count++ + '0';
    // }
}
bool isSafe(int x, int y)
{
    return (x < 8 && x >= 0 && y < 8 && y >= 0);
}
int SolveKTtil(int x, int y, int count, char** b)
{
    for (int direction = 0; direction < 8; direction++)
    {
        if (count == N*N) return 1;
        x += vertical[direction];
        y += horizontal[direction];
        if (isSafe(x, y) && b[x][y] == '0')
        {
            b[x][y] = count + '0';
            if (SolveKTtil(x, y, ++count, b))
            {
                printf("count: %2d x: %2d  y: %2d \n", count, x,y);
                return 1;
            }
            else
                b[x][y] = '0'; // backtracing
        }
        x -= vertical[direction];
        y -= horizontal[direction];
    }
    return -1;
}
/* A utility function to print solution matrix b[N][N] */
void printSolution()
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            printf(" %2d ", b[x][y] - '0');
        }
        printf("\n");
    }
}