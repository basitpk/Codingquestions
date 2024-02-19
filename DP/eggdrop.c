/**
 * The following is a description of the instance of this famous puzzle involving N = 2 eggs and a building with K = 36 floors.
Suppose that we wish to know which stories in a 36-story building are safe to drop eggs from, and which will cause the eggs to break on landing. We make a few assumptions:

1. An egg that survives a fall can be used again. 
2. A broken egg must be discarded. 
3. The effect of a fall is the same for all eggs. 
4. If an egg breaks when dropped, then it would break if dropped from a higher floor. 
5. If an egg survives a fall then it would survive a shorter fall. 
6. It is not ruled out that the first-floor windows break eggs, nor is it ruled out that the 36th-floor does not cause an egg to break.


If only one egg is available and we wish to be sure of obtaining the right result, the experiment can be carried out in only one way. 
Drop the egg from the first-floor window; if it survives, drop it from the second-floor window. Continue upward until it breaks. 
In the worst case, this method may require 36 droppings.
 Suppose 2 eggs are available. What is the least number of egg droppings that are guaranteed to work in all cases? 
The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that the total number of trials is minimized.
 * 
 * 
 * **/




// C program for the above approach

#include <limits.h>
#include <stdio.h>
#include <string.h>
#define MAX 1000

int memo[MAX][MAX];
int solveEggDrop(int n, int k)
{

	if (memo[n][k] != -1) {
		return memo[n][k];
	}

	if (k == 1 || k == 0)
		return k;

	if (n == 1)
		return k;

	int min = INT_MAX, x, res;

	for (x = 1; x <= k; x++) {
		int a = solveEggDrop(n - 1, x - 1);
		int b = solveEggDrop(n, k - x);
		res = a > b ? a : b;
		if (res < min)
			min = res;
	}

	memo[n][k] = min + 1;
	return min + 1;
}

// Driver code
int main()
{
	memset(memo, -1, MAX * MAX * sizeof(int));
	int n = 2, k = 36;
	printf("Minimum number of trials in worst case with %d eggs and %d floors is ",n,k);
		
	printf("%d", solveEggDrop(n, k));
	return 0;
}

// This code is contributed by repakaeswaripriya.
