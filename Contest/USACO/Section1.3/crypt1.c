/*
ID: yuweiic1
LANG: C
TASK: crypt1
*/

#include <stdio.h>
// function declaration
int inSet(int ckeckee, int set[]);

// global variable
int num;

int main()
{
    FILE *fin, *fout;
    fin = fopen("crypt1.in", "r");
    fout = fopen("crypt1.out", "w");
    fscanf(fin, "%d\n", &num);
    int set[num], count = 0;
    for (int i = 0; i < num; i++)
    {
        fscanf(fin, "%d", &set[i]);
    }
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            for (int k = 0; k < num; k++)
            {
                for (int l = 0; l < num; l++)
                {
                    for (int m = 0; m < num; m++)
                    {
                        int a = 100 * set[i] + 10 * set[j] + set[k];
                        int b = 10 * set[l] + set[m];
                        int c = set[m] * a;
                        int d = set[l] * a;
                        int e = a * b;
                        // Check partial and result fit the pattern
                        if (c < 1000 && d < 1000 && e >= 1000 && e < 10000)
                        { // quick filt
                            if (inSet(c, set) && inSet(d, set) && inSet(e, set))
                            { // check the number inside the pool
                                // printf("Set a: %2d b: %2d c: %3d d: %3d e: %3d\n", a, b, c, d, e);
                                count += 1;
                            }
                        }
                    }
                }
            }
        }
    }
    fprintf(fout, "%d\n", count);
    fclose(fin);
    fclose(fout);
    return 0;
}

int inSet(int checkee, int set[])
{
    while (checkee > 0)
    {
        int digit = checkee % 10;
        int isIn = 0;
        for (int i = 0; i < num; i++)
        {
            if (digit == set[i])
                isIn = 1;
        }
        if (!isIn)
            return 0;
        checkee /= 10;
    }
    return 1;
}