

/**
 * 
 * Given an array arr[] of n integers, construct a Product Array prod[] (of the same size) such 
 * that prod[i] is equal to the product of all the elements of arr[] except arr[i]. 
 *
 * Example #1 
 * 
 *  Input: arr[]  = {10, 3, 5, 6, 2}
    Output: prod[]  = {180, 600, 360, 300, 900}
    3 * 5 * 6 * 2 product of other array 
      elements except 10 is 180
    10 * 5 * 6 * 2 product of other array
       elements except 3 is 600
    10 * 3 * 6 * 2 product of other array 
       elements except 5 is 360
    10 * 3 * 5 * 2 product of other array 
 * 
 *
 * Time Complexity = O(N) 
 * **/


#include <stdio.h>

void prodArray(int prod[],int size, int arr[])
{
    int left[size], right[size], l=0, r=size-1;
    left[0]=right[0]=1;
    int count = 0;
    for(int i =1;i <= size;i++)
    {
        if(i<size)
        {
            left[i]=left[i-1]*arr[l];
            right[i]=right[i-1]*arr[r];
        }
        if(l>=r)
        {
            prod[l]=left[l]*right[size-1-l];
            prod[r]=left[r]*right[size-1-r];
        }
        l++;
        r--;
    }
    
    // printf("\nLeft = ");
    // for(int j=0; j < size; j++)
    // {
    //     printf("%d ",left[j]);
    // }
    // printf("\nRight = ");
    // for(int k=0; k < size; k++)
    // {
    //     printf("%d ",right[k]);
    // }
    
}
int main() {
    
    int arr[6]={1,2,3,5,7,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int prod[6]={0,0,0,0,0,0};
    
    prodArray(&prod[0], size, &arr[0]);
    
    printf("\n\n Output = ");
    for(int i=0; i < size; i++)
    {
        printf("%d ",prod[i]);
    }
    printf("\n\n");
    return 0;
}