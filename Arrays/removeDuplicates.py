''' Problem Statement=
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such 
that each unique element appears only once. The relative order of the elements should be kept the
 same. Then return the number of unique elements in nums.
 
-----Example --------
 
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


'''
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        i = 1
        LEN = len(nums) 
        if(LEN <= 1):
            return
        while(i < LEN):
            if(nums[i - 1] < nums[i]):
                i = i+1 
            else:
                nums.pop(i)
                LEN = len(nums)