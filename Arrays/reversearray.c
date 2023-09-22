/*
Problem Statement :
   Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
*/


void reverse(int *val, int l, int r)
{
    int temp=0;
    while(l < r)
    {
        temp = val[l];
        val[l]=val[r];
        val[r]=temp;
        l++;
        r--;
    }
}
void rotate(int* nums, int numsSize, int k){
    int rot=k%numsSize;
    reverse(nums, 0, numsSize -rot -1 );
    reverse(nums, numsSize-rot,numsSize -1);
    reverse(nums,0, numsSize-1);
}