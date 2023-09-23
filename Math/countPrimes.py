'''

Given an integer n, return the number of prime numbers that are strictly less than n.

---------------------- Example --------------------------------------

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

'''


class Solution:
    def countPrimes(self, n: int) -> int:
        if(n<=2):
            return 0
        p = 2
        primes=[True]*(n)
        while( p*p < n):
            if(primes[p] == True):
                i = p*p
                while(i < n):
                    primes[i] = False
                    i+=p       
            p+=1
        # print(primes)
        count = 0
        for i in range(2, len(primes)):
            if(primes[i]):
                count+=1
        return count