'''
You are given a 0-indexed array of integers nums, and an integer target.

Return the length of the longest subsequence of nums that sums up to target. If no such subsequence exists, return -1.

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
'''


class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        @cache
        def solve(i,val):
            if val==target:
                return 0
            if i>=len(nums) or val>target:
                return -1001
            
            return max(1+solve(i+1,val+nums[i]),solve(i+1,val))
            
            
        
        a=solve(0,0)
        solve.clear_cache()
        if a>0:
            return a
        return -1