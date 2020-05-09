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
 
    int len=max-min+1;
    int count[len]={0};
    for(int i=0;i<n;i++)
    {
        count[arr[i]-min]++;
    }
  // Change count[i] so that count[i] now contains actual  
    // position of this character in output array 
    	for(int i = 1; i < len; i++) 
	   	count[i] += count[i-1]; 
   
	  int output[n]={0};
  	for(int i = n-1; i >= 0; i--) 
	 { 
		 output[ count[arr[i]-min] -1 ] = arr[i]; //we do -1 coz if count stores 
             count[arr[i]-min]--;            //the actual pos of each element then 1st element 
                                             //in count has value 1 but our indexes in output array start with 0.hence 1 is subtracted
			         
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
