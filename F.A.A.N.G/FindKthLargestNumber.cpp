/*
Find the kth largest element in an unsorted array.
Note:It is the kth largest element in the sorted order, not the kth distinct element.

Input Format
First line contains integer n as size of array. Second line contains the value of k. Third line contains a single integer as element of array.

Constraints
1 ≤ k ≤ array's length.

Output Format
Print the kth largest element as output.

Sample Input
6
2
3 2 1 5 6 4
Sample Output
5

*/
#include<iostream>
#include <queue>
using namespace std;

int main() {
	int n,k;
cin>>n>>k;
int arr[n];
for(int i=0;i<n;i++)
{
	cin>>arr[i];
}
priority_queue <int,vector<int>,greater<int>> pq(arr,arr+k);
for(int i=k;i<n;i++)
{
	if(!pq.empty())
	{
		if(arr[i]>pq.top())
		{
			pq.pop();
			pq.push(arr[i]);
		}
	}
}
cout<<pq.top();
	return 0;
}
