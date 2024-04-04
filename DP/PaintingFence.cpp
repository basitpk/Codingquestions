/**
   Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 
   adjacent posts have the same color. Since the answer can be large return it modulo 10^9 + 7.

Examples:

Input : n = 2 k = 4
Output : 16
Explanation: We have 4 colors and 2 posts.
Ways when both posts have same color : 4 
Ways when both posts have diff color :4(choices for 1st post) * 3(choices for 2nd post) = 12

Input : n = 3 k = 2
Output : 6

**/


#include<iostream>
#include<cstring>
// #include<math>

using namespace std;


long countWays(int n, int k)
{
    long dp[n+1];
    memset(dp,0, sizeof(dp));
    dp[1]=k;
    dp[2]=k*k;
    const long mod = (long)1e9+7; 
    
    for (int i =3; i <=n; i++)
    {
        dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;
    }
    return dp[n];
}


int main()
{
    int n =3, k=5;
    cout << "\nNumber of ways = " << countWays(n, k) << endl;
    return 0;
}