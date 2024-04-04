/**
 
 Problem Statement :

    Count number od bits set in a number in the fastest way

  Asked in Zscaler

*/

#include <stdio.h>  

int NumberOfSetBits(int n)
{
    register unsigned int tmp;
    tmp = n - ((n >> 1) & 033333333333)
           - ((n >> 2) & 011111111111);
   return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}

int main()
{
    int n;
    printf("\nEnter a number =");
    scanf("%d",&n);
    printf("Number of set bits = %d",NumberOfSetBits(n));
    
    return 0;
}