'''

Problem Statement :

Given an integer array nums, find the subarray with the largest sum, and return its sum.


-------------- Example --------------------

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

'''

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_so_far = -10000
        max_ending = 0
        for i in range(0,len(nums)):
            max_ending = max_ending + nums[i]
            if(max_ending > max_so_far):
                max_so_far = max_ending
            if(max_ending < 0):
                max_ending = 0
        return max_so_far