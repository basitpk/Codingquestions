/*

Given a sorted array arr[] with possibly duplicate elements, the task is to find indexes of the first and last occurrences of an element x in the given array. 

Examples: 

Input : arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}, x = 5
Output : First Occurrence = 2
              Last Occurrence = 5

Input : arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125 }, x = 7

**/




// C program to find first and last occurrences of
// a number in a given sorted array
#include <stdio.h>

/* if x is present in arr[] then returns the index of
FIRST occurrence of x in arr[0..n-1], otherwise
returns -1 */
int first(int arr[], int x, int n)
{
	int low = 0, high = n - 1, res = -1;
	while (low <= high) {
		// Normal Binary Search Logic
		int mid = (low + high) / 2;
		if (arr[mid] > x)
			high = mid - 1;
		else if (arr[mid] < x)
			low = mid + 1;

		// If arr[mid] is same as x, we
		// update res and move to the left
		// half.
		else {
			res = mid;
			high = mid - 1;
		}
	}
	return res;
}

/* if x is present in arr[] then returns the index of
LAST occurrence of x in arr[0..n-1], otherwise
returns -1 */
int last(int arr[], int x, int n)
{
	int low = 0, high = n - 1, res = -1;
	while (low <= high) {
		// Normal Binary Search Logic
		int mid = (low + high) / 2;
		if (arr[mid] > x)
			high = mid - 1;
		else if (arr[mid] < x)
			low = mid + 1;

		// If arr[mid] is same as x, we
		// update res and move to the right
		// half.
		else {
			res = mid;
			low = mid + 1;
		}
	}
	return res;
}

// Driver program
int main()
{
	int arr[] = { 1, 2, 2, 2, 2, 3, 4, 7, 8, 8 };
	int n = sizeof(arr) / sizeof(int);

	int x = 8;
	printf("First Occurrence = %d\t", first(arr, x, n));
	printf("\nLast Occurrence = %d\n", last(arr, x, n));

	return 0;
}
