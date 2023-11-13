from typing import List
def minCost(n : int, p : List[int], f : List[int]) -> int:
        # code here
        dp={}
        def back(ind,total):
            if total>=n:return 0
            elif ind==n:return float("inf")
            if (ind,total) in dp:return dp[(ind,total)]
            val=0
            if p[ind]!=0:val=f[ind]
            dp[(ind,total)]=min(back(ind+1,total),back(ind+1,1+total+val)+p[ind])
            if(ind == 0 and total ==0):
                print(dp)
            return dp[(ind,total)]
        # print(dp)    
        return back(0,0)
n=4
p=[10,20,5,3]
f=[2,0,1,1]
k = minCost(n,p,f)
# print(k)    