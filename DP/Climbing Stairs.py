'''
Problem Statement :
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top ?

------------ Example ---------------

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
'''









class Solution:
    def climbStairs(self, n: int) -> int:
        if(n<=1):
            return n
        w=[0]*(n+1)
        # print(""+str(len(w)))
        w[1]=1
        w[2]=2
        for i in range(1,n-1):
            w[i+2]=w[i]+w[i+1]
        return w[n]