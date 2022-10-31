// C++ implementation to find length of longest
// strict bitonic subsequence
#include <bits/stdc++.h>
using namespace std;
	
// function to find length of longest
// strict bitonic subsequence
int longLenStrictBitonicSub(int arr[], int n)
{
	// hash table to map the array element with the
	// length of the longest subsequence of which
	// it is a part of and is the last/first element of
	// that subsequence
	unordered_map<int, int> inc, dcr;
	
	// arrays to store the length of increasing and
	// decreasing subsequences which end at them
	// or start from them
	int len_inc[n], len_dcr[n];
	
	// to store the length of longest strict
	// bitonic subsequence
	int longLen = 0;
	
	// traverse the array elements
	// from left to right
	for (int i=0; i<n; i++)
	{
		// initialize current length
		// for element arr[i] as 0
		int len = 0;
		
		// if 'arr[i]-1' is in 'inc'
		if (inc.find(arr[i]-1) != inc.end())
			len = inc[arr[i]-1];
		
		// update arr[i] subsequence length in 'inc'
		// and in len_inc[]
		inc[arr[i]] = len_inc[i] = len + 1;
	}
	
	// traverse the array elements
	// from right to left
	for (int i=n-1; i>=0; i--)
	{
		// initialize current length
		// for element arr[i] as 0
		int len = 0;
		
		// if 'arr[i]-1' is in 'dcr'
		if (dcr.find(arr[i]-1) != dcr.end())
			len = dcr[arr[i]-1];
		
		// update arr[i] subsequence length in 'dcr'
		// and in len_dcr[]
		dcr[arr[i]] = len_dcr[i] = len + 1;
	}
	
	// calculating the length of all the strict
	// bitonic subsequence
	for (int i=0; i<n; i++)
		if (longLen < (len_inc[i] + len_dcr[i] - 1))
			longLen = len_inc[i] + len_dcr[i] - 1;
		
	// required longest length strict
	// bitonic subsequence
	return longLen;	
}
	
// Driver program to test above
int main()
{
	int arr[] = {1, 5, 2, 3, 4, 5, 3, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Longest length strict bitonic subsequence = "
		<< longLenStrictBitonicSub(arr, n);
	return 0;
}

