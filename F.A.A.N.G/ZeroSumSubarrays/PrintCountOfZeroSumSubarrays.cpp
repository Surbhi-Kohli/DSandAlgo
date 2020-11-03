/*
You are given an array arr of size N. You need to print the total count of sub-arrays having their sum equal to 0

Input Format
First line of the input contains an integer T denoting the number of test cases
For each test case :
Line 1 : N the size of Array
Line 2 : N elements for Array

Constraints
1 <= T <= 100
1 <= N <= 10^6
-10^10 <= Ai <= 10^10

Output Format
For each test case, in a new line, print the total number of subarrays whose sum is equal to 0.

Sample Input
1
1
0
Sample Output
1

*/
#include<iostream>
#include<unordered_map>
using namespace std;
void tellNoOfZeroSumSubarray(int arr[],int n)
{
	int prefixSum[n+1];
	prefixSum[0]=0;
	for(int i=0;i<n;i++)
	{
		prefixSum[i+1]=prefixSum[i]+arr[i];
	}
	//for(int i=0;i<=n;i++)
	// cout<<prefixSum[i]<<" ";
	// cout<<endl;
	unordered_map<int,int> mp;
	for(int i=0;i<=n;i++)
	{
      mp[prefixSum[i]]++;
	  //cout<<mp[prefixSum[i]]<<" ";
	}
	// cout<<endl;
	
	int ans=0;
 for (auto i = mp.begin(); i != mp.end(); i++) 
	{ 
		if((i->second)>1)
		{   
             
			//cout<<i->second<<" is greater than 1"<<endl;
			int a=i->second;
	     	//cout<<a<<endl;
			
	      ans=ans+(a*(a-1))/2;
		}
	

	}
 cout<<ans<<endl;
}
int main() {
	int t,n;
	cin>>t;
  
   while(t--)
   {
	   cin>>n;
	   int arr[n];
	   for(int i=0;i<n;i++)
	   cin>>arr[i];
	   tellNoOfZeroSumSubarray(arr,n);

   }
	return 0;
}
