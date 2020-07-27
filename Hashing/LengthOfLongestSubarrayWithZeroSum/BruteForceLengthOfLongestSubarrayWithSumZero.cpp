/*
Find the length of largest subarray with 0 sum
Given an array of integers, find the length of the longest sub-array with sum equals to 0.
Examples :

Input: arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
Output: 5
Explanation: The longest sub-array with 
elements summing up-to 0 is {-2, 2, -8, 1, 7}

Input: arr[] = {1, 2, 3}
Output: 0
Explanation:There is no subarray with 0 sum

Input:  arr[] = {1, 0, 3}
Output:  1
Explanation: The longest sub-array with 
elements summing up-to 0 is {0}

Naive Approach: This involves the use of brute force where two nested loops are used. The outer loop is used to fix the
starting position of the sub array, and the inner loop is used for the ending position of the sub-array and if the sum of 
elements is equal to zero then increase the count.

Algorithm:
Consider all sub-arrays one by one and check the sum of every sub-array.
Run two loops: the outer loop picks the starting point i and the inner loop tries all sub-arrays starting from i.

Complexity Analysis:

Time Complexity: O(n^2) due to the use of nested loops.
Space complexity: O(1) as no extra space is used.

*/
#include <bits/stdc++.h> 
using namespace std; 
  
// Returns length of the largest subarray with 0 sum 
int checkSubarrayWithSumZero(int arr[], int n) 
{ 
    int max_len = 0; // Initialize result 
  
    // Pick a starting point 
    for (int i = 0; i < n; i++) { 
        // Initialize currr_sum for every starting point 
        int curr_sum = 0; 
  
        // try all subarrays starting with 'i' 
        for (int j = i; j < n; j++) { 
            curr_sum += arr[j]; 
  
            // If curr_sum becomes 0, then update max_len 
            // if required 
            if (curr_sum == 0) 
                max_len = max(max_len, j - i + 1); 
        } 
    } 
    return max_len; 
} 
  
// Driver program to test above function 
int main() {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cout<<checkSubarrayWithSumZero(arr,n);
	return 0;
}
