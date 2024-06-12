/**

Given a sorted array arr[] and a value X, find the k closest elements to X in arr[]. 

Examples: 

Input: K = 4, X = 35
       arr[] = {12, 16, 22, 30, 35, 39, 42, 
               45, 48, 50, 53, 55, 56}
Output: 30 39 42 45

**/


/* Function to find the cross over point (the point before 
which elements are smaller than or equal to x and after 
which greater than x)*/


#include <stdio.h> 

int findIntersection(int arr[], int low, int high, int x)
{
    // Base cases
    if(arr[high] <= x)
        return high;
    else if(arr[low] > x)
        return low;

    // Find the middle point 
    int mid = low + (high - low)/2;

    if(arr[mid] <= x && arr[mid+1] > x)
        return mid;

    /* If x is greater than arr[mid], then either arr[mid + 1] 
    is ceiling of x or ceiling lies in arr[mid+1...high] */
    if(arr[mid] < x)
        return findIntersection(arr, mid + 1, high, x);
    
    return findIntersection(arr, low, mid -1, x);
}


void printKclosest(int arr[], int x, int k, int n)
{
    int l = findIntersection(arr, 0, n-1, x);
    int r = l+1; // Right index to search 
    int count = 0; //  To keep track of count of elements already printed 

    if(arr[l]==x) l--;

    // Compare elements on left and right of crossover 
    // point to find the k closest elements 
    while(l >=0 && r < n && count < k)
    {
        if(x - arr[l] < arr[r] - x)
            printf("%d ", arr[l--]);
        else 
            printf("%d ", arr[r++]);
        count++;
    }

    while(count < k && l >=0)
    {   
       printf("%d ", arr[l--]);
       count++;
    }
       

    while(count < k && r < n)
    {
        printf("%d ", arr[r++]);
        count++;
    }   
}

// Driver program to test above functions
int main()
{
    int arr[] ={12, 16, 22, 30, 35, 39, 42, 
            45, 48, 50, 53, 55, 56}; 
    
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 35, k = 4; 
    // fflush(stdout);
    printKclosest(arr, x, 4, n);
    
    return 0;
}