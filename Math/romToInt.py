'''
Problem Statement :

Given a roman numeral, convert it to an integer. 



------------- Example ----------------

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.


'''







class Solution:
    def romanToInt(self, s: str) -> int:
        res =0
        for i in range(len(s) -1,-1,-1 ):
            if(s[i] == 'M'):
                val =1000
            elif(s[i] == 'D'):
                val =500
            elif(s[i] == 'C'):
                val =100
            elif(s[i] == 'L'):
                val =50
            elif(s[i] == 'X'):
                val = 10
            elif(s[i] == 'V'):
                val = 5
            elif(s[i] == 'I'):
                val = 1
            if(res >0 and val*4 < res):
                res =res - val
            else:
                res += val
        return res