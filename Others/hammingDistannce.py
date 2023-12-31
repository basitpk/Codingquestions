'''
Problem Statement :

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.


--------------------- Example ----------------------------

Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
'''

class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        count = 0
        for i in range(0,32):
            if((x & (1<<i)) ^ (y & (1<<i))):
                count+=1
        return count