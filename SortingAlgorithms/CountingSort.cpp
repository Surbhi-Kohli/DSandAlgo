/*
You are given an array, A. Sort this array using counting sort algorithm.

Input Format
First line contains a single integer, n, denoting the size of the array. Next line contains n integers, denoting the elements of the array.

Constraints
1<=N<=10^6 -10^6<=Ai<=10^6

Output Format
Print the array in sorted order.

Sample Input
5
1 3 2 6 5
Sample Output
1 2 3 5 6

*/

#include<bits/stdc++.h>
#include<climits>
using namespace std;
void countSort(int arr[],int n)
{
    int max=*max_element(arr,arr+n);
    int min=*min_element(arr,arr+n);
   // cout<<"min is "<<min<<endl;
    //cout<<"max is "<<max<<endl;
    int len=max-min+1;
    int count[len]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]-min]++;
    }
    
    //  for(int i=0;i<len;i++)
    //  {
    //      cout<<count[i]<<" ";
    //  }
    // cout<<endl;
	int output[n]={0};
	int k=0;
    for(int i=0;i<len;i++)
    {
        while(count[i]!=0)
        {  output[k++]=i+min;
            //cout<<i+min<<" ";
            count[i]--;
        }
    }
	for(int i=0;i<n;i++)
	cout<<output[i]<<" ";
}
int main() {
	int n;
	cin>>n;

 int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	countSort(arr,n);
	return 0;
}
