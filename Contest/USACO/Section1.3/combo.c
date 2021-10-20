/*
ID: yuweiic1
LANG: C
TASK: combo
*/
#include <stdlib.h>
#include <stdio.h>

// Global Variable
int dialNumber;
int combo[6];

// Function Declair
int check(int, int, int);
int isValid(int, int);

int main()
{
    FILE *fin, *fout;
    fin = fopen("combo.in", "r");
    if (fin == NULL)
    {
        printf("Error opening file: combo.in\n");
        exit(1);
    }
    fscanf(fin, "%d/n", &dialNumber);
    for (int i = 0; i < 6; i++)
    {
        fscanf(fin, "%d", &combo[i]);
    }
    // brute-force
    int cnt = 0;
    for (int i = 0; i < dialNumber; i++)
    {
        for (int j = 0; j < dialNumber; j++)
        {
            for (int k = 0; k < dialNumber; k++)
            {
                if (check(i, j, k))
                    cnt++;
            }
        }
    }
    fout = fopen("combo.out", "w");
    fprintf(fout, "%d\n", cnt);

    fclose(fin);
    fclose(fout);

    return 0;
}
int isValid(int a, int b)
{
    if (abs(a - b) <= 2)
        return 1;
    if (abs(a - b) >= dialNumber - 2)
        return 1;
    return 0;
}
int check(int a, int b, int c)
{
    return ((isValid(a, combo[0]) && isValid(b, combo[1]) && isValid(c, combo[2])) || (isValid(a, combo[3]) && isValid(b, combo[4]) && isValid(c, combo[5])));
}