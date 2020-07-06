/*
We can use hashing. The idea is to iterate through the array and for every element arr[i], calculate sum of
elements from 0 to i (this can simply be done as sum += arr[i]). If the current sum has been seen before, then 
there is a zero sum array. Hashing is used to store the sum values, so that we can quickly store sum and find
out whether the current sum is seen before or not.
EXAMPLE:
arr[] = {1, 4, -2, -2, 5, -4, 3}

If we consider all prefix sums, we can
notice that there is a subarray with 0
sum when :
1) Either a prefix sum repeats or
2) Or prefix sum becomes 0.

Prefix sums for above array are:
1, 5, 3, 1, 6, 2, 5

Since prefix sum 1 repeats, we have a subarray
with 0 sum. 

*/
#include <iostream>
#include <unordered_set>
using namespace std;

bool checkSubarrayWithZeroSum(int arr[],int n)
{
    unordered_set<int> mp;
    int sum=0;
    for(int i=0;i<n;i++)
    { sum+=arr[i];
      if(sum==0||mp.find(sum)!=mp.end())
        return true;
        
        mp.insert(sum);
    }
    return false;
}


int main() {
	// your code goes here
    int n;
    cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
     cin>>arr[i];
   if(checkSubarrayWithZeroSum(arr,n))
   {
       cout<<"subarray with sum 0 exists "<<endl;
   }
   else{
       cout<<" No subarray with sum 0 "<<endl;
   }
		return 0;
}
