/**
Given a positive integer N, the task is to find the number of ways to 
fill the board of dimension 2*N with a tile of dimensions 2 × 1, 1 × 2, (also known as domino) 
and an ‘L‘ shaped tile(also know as tromino) show below that can be rotated by 90 degrees.


1. If the value of N is less than 3, then print N as the total number of ways.
2. Initialize a 2-dimensional array, say dp[][3] that stores all the states of the dp.
3. Consider the Base Case: dp[0][0] = dp[1][0] = dp[1][1] = dp[1][2] = 1.
3. Iterate over the given range [2, N] and using the variable i and perform the following transitions in the dp as:

######################################     Main algorithm   ############################################
dp[i][0] equals (dp[i – 1][0] + dp[i – 2][0]+ dp[i – 2][1] + dp[i – 2][2]).
dp[i][1] equals dp[i – 1][0] + dp[i – 1][2].
dp[i][2] equals dp[i – 1][0] + dp[i – 1][1].
After completing the above steps, print the total number of ways stored in dp[N][0]


State 0 = both rows filled
State 1 = upper row filled only
State 2 = lower row filled only

**/

// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

// Function to find the total number
// of ways to tile a 2*N board using
// the given types of tile
int numTilings(int N)
{
	// If N is less than 3
	if (N < 3) {
		return N;
	}

	// Store all dp-states
	vector<vector<long long> > dp(
		N + 1, vector<long long>(3, 0));

	// Base Case
	dp[0][0] = dp[1][0] = 1;
	dp[1][1] = dp[1][2] = 1;

	// Traverse the range [2, N]
	for (int i = 2; i <= N; i++) {

		// Update the value of dp[i][0]
		dp[i][0] = ( dp[i-1][0]+dp[i-2][0] )+ (dp[i-2][1]+dp[i-2][2]) % MOD;
        /* Two vertical columns at i-1  or two trominos at i-2*/


		// Update the value of dp[i][1]
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        // vertical column at i - 1 location and lower tromino at i-1 location 
		
        // Update the value of dp[i][2]
		dp[i][2] = (dp[i - 1][0]+ dp[i - 1][1]) % MOD;
        // vertical column at i - 1 location and lower tromino at i-1 location 
	}

	// Return the number of ways as
	// the value of dp[N][0]
	return dp[N][0];
}

// Driver Code
int main()
{
	int N = 3;
	cout << numTilings(N);

	return 0;
}
