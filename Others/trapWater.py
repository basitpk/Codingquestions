'''
Problem Statement :

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

---------------------- Example ----------------------------------------

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped

'''


class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if(len(height) <=1):
            return 0
        l,r = 0, len(height) - 1
        res = 0
        leftMax, rightMax = 0,0
        while l < r:
            leftMax, rightMax = max(height[l], leftMax), max(height[r], rightMax)
            if(height[l] < height[r]):
                res += leftMax - height[l]
                l += 1
            else:
                res += rightMax - height[r]
                r -= 1
        return res