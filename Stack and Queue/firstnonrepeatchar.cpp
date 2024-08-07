/**

    Given a stream of characters, find the first non-repeating character
    from the stream. You need to tell the first non-repeating character in O(1) 
    time at any moment

**/

#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{

	// ans string stores the final answer
	string ans = "";
	// map to find uniqueness of an element
	unordered_map<char, int> mp;
	queue<char> q;
	// queue to keep non-repeating element at the front.
	for (int i = 0; i < A.length(); i++) {
		// if non-repeating element found push it in
		// queue and count in map
		if (mp.find(A[i]) == mp.end()) {
			q.push(A[i]);
		}
		mp[A[i]]++;
		// if anytime front element is repeating pop it
		// form queue
		while (!q.empty() && mp[q.front()] > 1) {
			q.pop();
		}
		// if queue is not empty append front element
		// else append "#" in ans string.
		if (!q.empty()) {
			ans += q.front();
		}
		else {
			ans += '#';
		}
	}
	// return ans
	return ans;
}

int main()
{
	string A = "geeksforgeeksandgeeksquizfor";
	string ans = FirstNonRepeating(A);
	cout << ans << "\n";
	return 0;
}
