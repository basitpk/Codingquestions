#include<stdio.h>


int count = 5;
int main()
{
    int i =0, j=0,k;
    int arr[5]={10,3,2,5,5};
    for (i=1; i< count; i++)
    {
        // for ( j = i-1; j >= 1; j--)
        // {
        //     if(arr[j] > arr[i])
        //         arr[j+1] = arr[j];
        //     else
        //         break;
        // }
        // arr[j+1]=arr[i];
        k = arr[i];
        // printf("\n%d",k);
        j=i-1;
        while(j>=0 && arr[j] > k)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=k;
        // break;
    }
    for (int k =0; k<count; k++)
       printf("\n %d", arr[k]);
    
    return 0;
}