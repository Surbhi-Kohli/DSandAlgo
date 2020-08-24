/*
A Simple but inefficient method
Traverse the input price array. For every element being visited, traverse elements on left of it and increment the
span value of it while elements on the left side are smaller.

Time Complexity of the above method is O(n^2).
*/

#include <iostream>
#include <stack>
using namespace std;
void stockSpanProblem(int arr[],int n,int S[])
{
  S[0]=1;
  for(int i=1;i<n;i++)
  {
      S[i]=1;
      for(int j=i-1;j>=0 && arr[i]>=arr[j];j--)
      S[i]++;
  }
  for(int j=0;j<n;j++)
  cout<<S[j]<<" ";
    
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int S[n];
    stockSpanProblem(arr,n,S);
	return 0;
}
