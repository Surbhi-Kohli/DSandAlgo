/*
Longest sub-array having sum k
Given an array arr[] of size n containing integers. The problem is to find the length of the longest sub-array having sum equal to the given value k.

Examples:

Input : arr[] = { 10, 5, 2, 7, 1, 9 }, 
            k = 15
Output : 4
The sub-array is {5, 2, 7, 1}.

Input : arr[] = {-5, 8, -14, 2, 4, 12},
            k = -5
Output : 5
Naive Approach: Consider the sum of all the sub-arrays and return the length of the longest sub-array having sum ‘k’. Time Complexity is of O(n^2).


Efficient Approach: Following are the steps:
* Initialize sum = 0 and maxLen = 0.
* Create a hash table having (sum, index) tuples.
* For i = 0 to n-1, perform the following steps:
   1.Accumulate arr[i] to sum.
   2.If sum == k, update maxLen = i+1.
   3.Check whether sum is present in the hash table or not. If not present, then add it to the hash table as (sum, i) pair.
   4.Check if (sum-k) is present in the hash table or not. If present, then obtain index of (sum-k) from the hash table as index.
      Now check if maxLen < (i-index), then update maxLen = (i-index).
* Return maxLen.

Time Complexity: O(n).
Auxiliary Space: O(n).

Input         Output
3              2
1 1 1
2
*/


#include <iostream>
#include <unordered_map>
using namespace std;
int checkSubarrayWithSumZero(int arr[],int n,int k)
{
    unordered_map<int,int> prefixSum;
    int sum=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        // if(arr[i]==0 && len==0)
        // len=1;
        if(sum==k)
        len=max(i+1,len);
        if(prefixSum.find(sum-k)!=prefixSum.end())
        { cout<<"if condition "<<sum-k<<"and sum is "<<sum<<endl;
           len=max(len,i-prefixSum[sum-k]);  
        }
       
       else{
           prefixSum[sum]=i;
       } 
        
        
    }
    return len;
    
    
}
int main() {
int n,k;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cin>>k;
cout<<checkSubarrayWithSumZero(arr,n,k);
	return 0;
}
