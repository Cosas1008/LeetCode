/*
ID: yuweiic1
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <stdlib.h>

int n;
int Equal(char **a, char **b)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            // printf("A: %c B: %c", a[i][j], b[i][j]);
            if (a[i][j] != b[i][j])
                return 0;
        }
    }
    return 1;
}
void r90(char **transformed, char **original)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transformed[j][n - i - 1] = original[i][j];
        }
    }
}

void filp(char **transformed, char **original)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transformed[i][n - j - 1] = original[i][j];
        }
    }
}

int main()
{
    int i, j, k, identical = 0, opt = 0;
    char **ori, **tag, **tmp1, **tmp2; // 2d char array
    FILE *fin, *fout;

    // Read File
    fin = fopen("transform.in", "r");
    fscanf(fin, "%d", &n);

    // memory allocation
    // modefied sizeof(char) to sizeof(char*)
    ori = (char **)malloc(n * sizeof(char *));
    tag = (char **)malloc(n * sizeof(char *));
    tmp1 = (char **)malloc(n * sizeof(char *));
    tmp2 = (char **)malloc(n * sizeof(char *));
    for (i = 0; i < n; i++)
    {
        ori[i] = (char *)malloc(n * sizeof(char));
        tag[i] = (char *)malloc(n * sizeof(char));
        tmp1[i] = (char *)malloc(n * sizeof(char));
        tmp2[i] = (char *)malloc(n * sizeof(char));
    }

    // load data
    for (i = 0; i < n; i++)
    {
        fscanf(fin, "%s", &ori[i][0]);
        // printf("%c%c%c%c%c\n",ori[i][0], ori[i][1], ori[i][2], ori[i][3], ori[i][4]); // n = 5
    }
    for (i = 0; i < n; i++)
    {
        fscanf(fin, "%s", &tag[i][0]);
        // printf("%c%c%c%c%c\n",tag[i][0], tag[i][1], tag[i][2], tag[i][3], tag[i][4]); // n = 5
    }
    // Close input file
    fclose(fin);

    //check identical
    r90(tmp1, ori); //90   cw opt:1
    if (Equal(tmp1, tag))
        opt = 1;
    else
    { //180  cw opt:2
        r90(tmp2, tmp1);
        if (Equal(tmp2, tag))
            opt = 2;
        else
        { //270  cw opt:3
            r90(tmp1, tmp2);
            if (Equal(tmp1, tag))
                opt = 3;
            else
            { //nochange  opt:6
                if (Equal(ori, tag))
                    opt = 6;
                else
                { // flip opt:4
                    filp(tmp1, ori);
                    if (Equal(tmp1, tag))
                        opt = 4;
                    else
                    { //90  fcw opt:5
                        r90(tmp2, tmp1);
                        if (Equal(tmp2, tag))
                            opt = 5;
                        else
                        { //180 fcw opt:5
                            r90(tmp1, tmp2);
                            if (Equal(tmp1, tag))
                                opt = 5;
                            else
                            { //270  fcw opt:5
                                r90(tmp2, tmp1);
                                if (Equal(tmp2, tag))
                                    opt = 5;
                                else
                                { // invalid transform
                                    opt = 7;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // Output file
    fout = fopen("transform.out", "w");
    fprintf(fout, "%d\n", opt);
    // Close output file
    fclose(fout);

    // Free dynamic allocated memory
    for (i = 0; i < n; i++)
    {
        free(ori[i]);
        free(tag[i]);
        free(tmp1[i]);
        free(tmp2[i]);
    }

    free(ori);
    free(tag);
    free(tmp1);
    free(tmp2);
    return 0;
}