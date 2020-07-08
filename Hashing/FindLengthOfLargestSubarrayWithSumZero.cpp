/*
Find the length of largest subarray with 0 sum
Given an array of integers, find the length of the longest sub-array with sum equals to 0.

Naive Approach: This involves the use of brute force where two nested loops are used. The outer loop is used to fix the
starting position of the sub array, and the inner loop is used for the ending position of the sub-array and if the sum of elements
is equal to zero then increase the count.

Algorithm:
Consider all sub-arrays one by one and check the sum of every sub-array.
Run two loops: the outer loop picks the starting point i and the inner loop tries all sub-arrays starting from i.

Complexity Analysis:
Time Complexity: O(n^2) due to the use of nested loops.
Space complexity: O(1) as no extra space is used.

Efficient Approach  :We will store prefixSum and its index in hashmap
Algorithm:
1.Create a extra space, an array of length n (prefix), a variable (sum) , length (max_len) and a hash map (hm) to store sum-index pair as a key-value pair.
2.Move along the input array from starting to the end.
3.For every index update the value of preSum = preSum + array[i].
4.Check for every index, if the current sum is present in the hash map or not
   *If present update the value of max_len to maximum of difference of two indices (current index and index in the hash-map) and max_len
   *Else Put the value (sum) in the hash map, with the index as a key-value pair.
5.Print the maximum length (max_len)


Example:
Input:             Output:3
6
0 -1 1 2 -5 5

Input:                Output:7
7 
0 -1 1 -2 -5 5 2   

Input:             Output:3
5
1 2 5 3 -8   


*/
#include <iostream>
#include <map>
using namespace std;

void findLengthOfLargestSubarrayWithSumZero(int arr[],int n)
{
    map<int,int> mp;
    int len=0,pre=0;
    for(int i=0;i<n;i++)
    { 
      pre+=arr[i];  
        if(arr[i]==0 && len==0)
        len=1;
        
        if(pre==0)
        { 
         len=max(len,i+1);    
        }
        
        
        if(mp.find(pre)!=mp.end())
        {
            len=max(len,i-mp[pre]);
        }
        else{
            mp[pre]=i;
        }
    }
    cout<<len;
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	findLengthOfLargestSubarrayWithSumZero(arr,n);
	return 0;
}
