/**
 * 
 * Given an array arr[] of size N consisting of  1, 2, and 3 only, the task is to sort the given array in ascending order.
 * 
 * 
*/


#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int arr[], int N)
{
    int i = 0, j = N-1, mid = 0;

    while(mid <=j)
    {
        if(arr[mid] == 1)
        {
           swap(&arr[i], &arr[mid]);
           mid++;
           i++;
        }
        else if(arr[mid]==3)
        {
            swap(&arr[j], &arr[mid]);
            // mid++;
            j--;
        }
        else{
            mid++;
        }   
    }
    while(i<=j)
    {
        if(arr[i] == 2)
        {
            swap(&arr[i], &arr[j]);
            j--;
        }
        else
            i++;
    } 
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
}


// Driver Code
int main()
{
    int arr[] = { 3, 2, 1, 1, 2, 3, 1, 2 };
    int N = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, N);
 
    return 0;
}