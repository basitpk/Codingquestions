'''
Given a string s, return the longest palindromic substring in s.


------------------- Example 1: ----------------------------

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.


---------------------Example 2:-------------------------

Input: s = "cbbd"
Output: "bb"


'''

class Solution:
    def longestPalindrome(self, s: str) -> str:
        def expand(myStr, l: int , r : int):
            while(l >= 0 and r < len(myStr) and myStr[l] == myStr[r]):
                l-=1
                r+=1
            return myStr[l+1:r]    
        result=""
        for i in range(0,len(s)):
            sub1 = expand(s,i,i)
            if(len(sub1) > len(result)):
                result = sub1
            sub2 = expand(s,i,i+1)
            if(len(sub2) > len(result)):
                result = sub2
        return result        
