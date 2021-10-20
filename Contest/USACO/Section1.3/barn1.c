/*
ID: yuweiic1
LANG: C
TASK: barn1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void *a, const void *b)
{
    int int_a = *((int *)a);
    int int_b = *((int *)b);

    if (int_a == int_b)
        return 0;
    else if (int_a < int_b)
        return -1;
    else
        return 1;
}
int main(int argc, char const *argv[])
{
    FILE *fin, *fout;
    int m, s, c;
    int *stall, *interval;
    fin = fopen("barn1.in", "r");
    fscanf(fin, "%d %d %d", &m, &s, &c);
    stall = malloc(c * (sizeof(int)));
    memset(stall, 0, c * (sizeof(int))); // int is 4-byte data for 64-bit system

    for (int i = 0; i < c; i++)
    {
        fscanf(fin, "%d", &stall[i]);
    }
    // sort the stall ascend
    qsort(stall, c, sizeof(int), compare);
    int space;
    interval = malloc((c - 1) * (sizeof(int)));
    memset(interval, 0, (c - 1) * (sizeof(int)));
    fout = fopen("barn1.out", "w");
    for (int i = 0; i < c - 1; i++)
    {
        space = stall[i + 1] - stall[i];
        interval[i] = space;
        // fprintf(fout, "original interval for Stall %d and Stall %d is %d\n",stall[i + 1], stall[i], interval[i]); // debug
    }
    qsort(interval, (c - 1), sizeof(int), compare);
    // note:: sizeof(interval) / sizeof(*interval) not working for (void *)
    int answer = 0;
    // printf("M: %d C-M : %d\n", m, c-m); // debug
    if(m > c){
        fprintf(fout, "%d\n", c); // the board is not enough for covering up all the stall
        // therefore, we have to cover min(c) stall
    }else{
        for (int i = 0; i < c - m; i++)
        {
            answer += interval[i];
            // fprintf(fout, "ordered interval : %d\n", interval[i]); // debug
        }
        answer += m; // add the number of boards back
        fprintf(fout, "%d\n", answer);
    }
    
    fclose(fin);
    fclose(fout);
    free(stall);
    free(interval);
    return 0;
}
