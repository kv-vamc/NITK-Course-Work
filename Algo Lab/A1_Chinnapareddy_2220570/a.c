#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long int* a, long int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Insertion sort
void insertionSort(long int arr[], long int n)
{
    long int i, key, j;

    for(i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Quick Sort
int partition (long int arr[], int low, int high) 
{ 
    int i, j; 
    i = low - 1;

    int pivot = arr[high];
  
    for(j = low; j <= high - 1; j++) 
    { 
        if(arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return i + 1; 
} 
  

void quickSort(long int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int ind = partition(arr, low, high); 
  
        quickSort(arr, low, ind - 1); 
        quickSort(arr, ind + 1, high); 
    } 
} 

//Merge Sort

void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0;
    j = 0;
    k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long int arr[], int l, int r)
{
    if(l < r)
    {
        int mid = l + (r - l) / 2;
 
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
 
        merge(arr, l, mid, r);
    }
}

int main()
{
    long int n;
    int it = 0;
  
    double tim_ins[10], tim_quick[10], tim_merge[10];
  
    printf("Input size, Insertion Sort, Quick Sort, Merge Sort\n");
  
    long int input_size[] = {10, 20, 70, 90, 1000, 2000, 5000, 10000, 20000, 30000, 50000, 70000, 100000}; 

    while(it++ < 13)
    {
        n = input_size[it - 1];

        long int ins[n], quick[n], merge[n];

        for (int i = 0; i < n; i++) {
            long int num = rand() % n + 1;
            ins[i] = num;
            quick[i] = num;
            merge[i] = num;
        }
  
        clock_t start, end;
  
        // Insertion sort
        start = clock();
        insertionSort(ins, n);
        end = clock();
  
        tim_ins[it] = ((double)(end - start));
  
        // Quick sort
        start = clock();
        quickSort(quick, 0, n-1);
        end = clock();
  
        tim_quick[it] = ((double)(end - start));
  
        // Merge sort
        start = clock();
        mergeSort(merge,0, n-1);
        end = clock();
  
        tim_merge[it] = ((double)(end - start));
  
        printf("%li, %li, %li, %li\n", n, (long int)tim_ins[it], (long int)tim_quick[it], (long int)tim_merge[it]);
    }
  
    return 0;
}
