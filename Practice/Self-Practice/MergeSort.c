#include <stdio.h>

// merge sort function
void mergeSort(int a[], int p, int r){
    int q;
    if(p < r){
        m = (p + r) / 2;
        mergeSort(a, p, m);
        mergeSort(a, m+1, r);
        merge(a, p, r, n);
    }
}

// function to merge the subarrays
void merge(int a[], int p, int r, int q)
{
    int n = sizeof(a)/sizeof(a[0]);
    int b[n];   //same size of a[]
    int i, j, k;
    k = 0;
    i = p;
    j = q + 1;

    while(i <= q && j <= r){
        if(a[i] < a[j])
            b[k++] = a[i++];    // same as b[k]=a[i]; k++; i++;
        else
            b[k++] = a[j++];
    }
  
    while(i <= q){
        b[k++] = a[i++];
    }
  
    while(j <= r){
        b[k++] = a[j++];
    }
  
    for(i=r; i >= p; i--){
        a[i] = b[--k];  // copying back the sorted list to a[]
    } 
}

// function to print the array
void printArray(int a[], int size)
{
    for(int i=0; i < size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
 
int main()
{
    int arr[] = {32, 45, 67, 2, 7};
    int len = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array: \n");
    printArray(arr, len);
    
    // calling merge sort
    mergeSort(arr, 0, len - 1);
 
    printf("\nSorted array: \n");
    printArray(arr, len);
    return 0;
}