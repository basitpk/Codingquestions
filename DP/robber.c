/**

Problem Statement  :

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.




------------------Example ---------------------

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


**/


#define MAX(a,b) ((a) > (b) ? (a) :(b))

int rob(int* nums, int numsSize)
{
   int *dp = (int *)malloc(sizeof(int)*numsSize);
   int i =0;
   for (i =0; i < numsSize;i++)
   {
       switch(i)
       {
           case 0:
               dp[i]=nums[0];
               break;
           case 1:
               dp[i] = MAX(nums[1],dp[i-1]);
               break;
           default:
               dp[i] = MAX(nums[i]+dp[i-2], dp[i-1]);
       }
   }
    return dp[numsSize -1];
}


