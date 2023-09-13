'''
Problem Statement  You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. 
However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

-----Example --------

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
'''




class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        max_profit = 0
        profit = 0
        peak = prices[0]
        valley = prices[0]
        for i in range(1,len(prices)):
            # k = 0
            # max_profit = 0
            # lsf =prices[0]+1
            # while (k < i):
            if(prices[i]>=prices[i-1]):
                peak = prices[i]    
                # profit =
                if(i == len(prices) - 1):
                    max_profit += peak - valley
            else:
                    max_profit+=peak - valley
                    valley = prices[i]
                    peak = valley
            #     print("Profit="+str(profit))
            # print("\n")     
        return max_profit      
        