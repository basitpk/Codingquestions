'''
Problem Statement
Write a function to find the longest common prefix string amongst an array of strings

------ Example -------------

Input: strs = ["flower","flow","flight"]
Output: "fl"
'''

from typing import List


class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        strs.sort()
        length =min(len(strs[0]),len(strs[-1]))
        i = 0
        while((i < length) and (strs[0][i]==strs[-1][i])):
            i+=1
        return strs[0][0:i]    
        # print(strs)