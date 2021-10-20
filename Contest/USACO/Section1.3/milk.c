/*
ID: yuweiic1
LANG: C
TASK: milk
*/
#include <stdio.h>
#include <stdlib.h>

struct farmer
{
    int unit;
    int price;
};

typedef struct farmer farm; // farm is struct array

// refer https://stackoverflow.com/questions/1787996/c-library-function-to-do-sort
int comp(const void *element1, const void *element2)
{
    farm first = *((farm *)element1);
    farm second = *((farm *)element2);
    if (first.price > second.price)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main()
{
    FILE *fin, *fout;
    int amount, n_farmer;
    int i;
    fin = fopen("milk.in", "r");
    fout = fopen("milk.out", "w");
    fscanf(fin, "%d %d", &amount, &n_farmer);
    farm list[n_farmer];
    for (i = 0; i < n_farmer; i++)
    {
        fscanf(fin, "%d %d", &list[i].price, &list[i].unit);
    }
    fclose(fin);

    // sort the list in ascend order
    qsort(list, sizeof(list) / sizeof(*list), sizeof(farm), comp);

    // Greedy technique take place
    int left = amount, cost = 0;
    for (int n = 0; n < n_farmer; n = n + 1)
    {
        // printf("left: %d, list[i].unit = %d\n", left, list[n].unit);
        if (left > list[n].unit)
        {
            cost += list[n].unit * list[n].price;
            left -= list[n].unit;
        }
        else
        {
            cost += left * list[n].price;
            break;
        }
    }
    fprintf(fout, "%d\n", cost);
    fclose(fout);
    return 0;
}