/*
Given K sorted arrays each with N elements merge them and output the sorted array

Input Format
First line contains 2 space separated integers K and N.
K is number of arrays.
N is number of elements in each array.
Next K lines contain N space separated integers each where ith line denotes the element of ith sorted array.

Constraints
Elements of array <= |10^15|
N <= 10^5
K <= 10

Output Format
Single line consisting of space separated numbers

Sample Input
3 4
1 3 5 7
2 4 6 8
0 9 10 11
Sample Output
0 1 2 3 4 5 6 7 8 9 10 11
Explanation
If we were to combine all the arrays into one and then sort it , the output would be as above.



*/
#include<iostream>
#include <queue>
using namespace std;
typedef pair<long long int,pair<int,int>> customPair;
void mergeKSortedArrays(vector<vector<int>> arr,int n,int k)
{
priority_queue<customPair,vector<customPair>,greater<customPair>> pq;
for(int i=0;i<k;i++)
{
	pq.push({arr[i][0],{i,0}});
}
while(!pq.empty())
{
	customPair curr=pq.top();
	pq.pop();
	int arrayForElement=curr.second.first;
	int index=curr.second.second;
	cout<<curr.first<<" ";
    if(index+1<arr[arrayForElement].size())
	{
		pq.push({arr[arrayForElement][index+1],{arrayForElement,index+1}});
	}
}
}
int main() {
	int k;
	long long int n;
	cin>>k>>n;

   vector<vector<int> > arr( k,vector<int> (n)); //creating a 2d vector based on input values of n and k
	//It will be vector with k rows and n cols
	  for(int i=0;i<k;i++)
	  {
		  for(int j=0;j<n;j++)
		  {
			  cin>>arr[i][j];
		  }
	  }

mergeKSortedArrays(arr,n,k);
	return 0;
}
