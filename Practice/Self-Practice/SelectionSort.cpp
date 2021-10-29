#include <bits/stdc++.h>
using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(vector<int> arr){
    int i, j, min_idx;
    int n = arr.size();
    for(int i = 0; i < n-1; ++i){
        min_idx = i;
        for(j = i+1; j < n; ++j)
            if(arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);
    }
}