/*
Given N students in a line and their marks, you have to distribute candies in such a way that every child must
get atleast one candy and children with strictly higher marks than their neighbours get more candies than them.
You have to tell what is the minimum number of candies needed for this task.

Input Format
First line contains a single element N. Next line contains N elements denoting the marks of N children in order.

Constraints
N<=100000
0<=Marks<1000

Output Format
Print a single line containing minimum number of candies required to fulfil the above conditions.

Sample Input
3
1 2 2
Sample Output
4
Explanation
Children will get 1,2,1 candies respectively.

Approach:
Step1:Compare each child with its left neighbour and give candies
Step2:Compare each child with its right neighbour and update candies if they need to be updated

Time Complexity:O(n)
*/

#include<iostream>
using namespace std;
int distributeCandies(int arr[],int n)
{
	int candies[n];
	candies[0]=1;
   for(int i=1;i<n;i++)
   {
	  if(arr[i]>arr[i-1] )
	   { 
         candies[i]=candies[i-1]+1;
		
	   }
	   else candies[i]=1;

   }
   for(int i=n-2;i>=0;i--)
   {
	   if(arr[i]>arr[i+1])
	   {
		   if(candies[i]<=candies[i+1])
		   candies[i]=candies[i+1]+1;
	   }
     
   }
   int count=0;
  
   for(int i=0;i<n;i++)
    count=count+candies[i];
	return count;
}
int main () {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<distributeCandies(arr,n);
	return 0;
}
