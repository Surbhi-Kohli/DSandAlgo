INCREASING DECREASING SEQUENCE
Take the following as input.

A number (N)
Take N more numerical inputs
The N inputs for a sequence S = s1, s2, .., sN. Compute if it is possible to split sequence into two sequences -
s1 to si and si+1 to sN such that first sequence is strictly decreasing and second is strictly increasing. Print true/false as output.

Input Format:
Constraints:
0 < N < 1000 Each number in sequence S is > 0 and < 1000000000
Sample Input             Sample Output
5                         true
1 
2 
3 
4 
5
#include<iostream>
using namespace std;
int main() {
  int n,i=1,k=0;
  cin>>n;
  
  int arr[n];
  for(int j=0;j<n;j++)
  {
    cin>>arr[j];
  }
  for(int j=0;j<n-1;j++)
  {
    if(arr[j]==arr[j+1])
    {
    cout<<"false";
    return 0;
    }
  }
  
  if(arr[i-1]==arr[i])
  {
      cout<<"false";
      return 0;
  }
  while(arr[i-1]>arr[i] && i<n)
  {
    i++;
  }
  if(i==n)
  cout<<"true";
 
  else{
  if(i==1)
       k=0;
     else
       k=i;
  
    while(arr[k]<arr[k+1]&& k<=n-2)
    {
      k++;
    }
   
     if(k==n-1)
    cout<<"true";
    else
    cout<<"false";
  }
  
	return 0;
}
