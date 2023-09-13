
'''
 Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1

 ----Example---
 Input: s = "leetcode"
 Output: 0

 Input: t = "leetcode"
 Output: 3
'''




class Solution:
    def firstUniqChar(self, s: str) -> int:
        count = Counter(s)
        for i,j in count.items():
            if(j==1):
                return s.index(i)
        return -1