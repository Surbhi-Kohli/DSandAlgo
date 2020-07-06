/*
A simple solution is to consider all subarrays one by one and check the sum of every subarray.
We can run two loops: the outer loop picks a starting point i and the inner loop tries all subarrays starting
from i . Time complexity of this method is O(n^2).
Input:                  Output:subarray with sum 0 exists 
5
4 2 -3 1 6
*/


#include <iostream>
using namespace std;

bool checkSubarrayWithZeroSum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    { sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=arr[j];
        }
        if(sum==0)
        return true;
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
