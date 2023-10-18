/**
Write a program to sort array using quick sort

Input : [7,5,8,4,3,1,2,6]
Output : [1,2,3,4,5,6,7,8]
The key process in quickSort is a partition(). The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the left of the pivot, and all greater elements to the right of the pivot.

Step 1 : [6,5,8,4,3,1,2,7]
i =2, j=6
step 2 : [6,5,2,4,3,1,8,7]

**/

#include <stdio.h>

void swap(int *t1, int *t2)
{
    int temp =*t1;
    *t1 = *t2;
    *t2 = temp;
}

int cpivot(int *low, int*high)
{
    if (*low > *high)
    swap(low,high);
    return *low;
}

int partition(int arr[], int low , int high)
{
   int pivot = cpivot(&arr[low], &arr[high]);
   int i = low, j = high;
   do
   {
     do ++i; while(arr[i]<pivot);
     do --j; while(arr[j]>pivot);
     if(i < j)
        swap(&arr[i],&arr[j]);
   }while(i<j);

   swap(&arr[j],&arr[low]);
   return j;
}
void quickSort(int arr[], int low, int high)
{
    
    if(low<high)
    { 
        int k = partition(arr, low, high);
        quickSort(arr, low, k-1);
        quickSort(arr, k+1, high);
    }
}
int main() {
    // Write C code here
    int arr[8]={2,5,8,6,3,1,4,7};
    quickSort(arr, 0, 7);
    for(int i =0; i< 8; i++)
      printf("%d,",arr[i]);

    return 0;
}