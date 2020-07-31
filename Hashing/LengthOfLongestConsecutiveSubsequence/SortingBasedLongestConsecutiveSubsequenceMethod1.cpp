/*
Longest Consecutive Subsequence
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers,
the consecutive numbers can be in any order.

Examples:

Input: arr[] = {1, 9, 3, 10, 4, 20, 2}
Output: 4
Explanation: 
The subsequence 1, 3, 4, 2 is the longest 
subsequence of consecutive elements

Input: arr[] = {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}
Output: 5
Explanation: 
The subsequence 36, 35, 33, 34, 32 is the longest 
subsequence of consecutive elements.

Naive Approach: The idea is to first sort the array and find the longest subarray with consecutive elements.
After sorting the array run a loop and keep a count and max (both initially zero). Run a loop from start to end and if the
current element is not equal to the previous (element+1) then set the count to 1 else increase the count. Update max with a maximum of count and max.
O(nlogn)

*/
#include <iostream>
#include <algorithm>
using namespace std;
void checkLongestConsecutiveSubsequences(int arr[],int n)
{
    sort(arr,arr+n);
  //we hv l initialized to 1 as min len subsequence would be 1
    int l=1,max_len=1;
    for(int i=1;i<n;i++)
    {  
        if(arr[i-1]+1==arr[i])
        {
            l++;
          
        }
        else
        {
             max_len=max(l,max_len);
             l=1;
        }
       
    }
    cout<<max_len<<endl;
}
int main() {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}

checkLongestConsecutiveSubsequences(arr,n);
	return 0;
}
