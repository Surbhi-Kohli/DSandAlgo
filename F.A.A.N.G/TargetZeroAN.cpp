/*
Given an integer n, return an array containing n unique integers such that they add up to 0.

Input Format
First line contains an integers n.

Constraints
None

Output Format
Array integers summing upto 0.

Sample Input
5
Sample Output
-2 -1 0 1 2
Explanation
Output should be in sorted order.


*/
#include<iostream>
#include <cmath>
#include<vector> 
using namespace std;
void targetZero(int arr[],int n)
{
    vector<int> v;
    int n1=floor(n/2.0);
  int k=0;
  
  int n2=n1*-1;
  
  for(int i=n2;i<=-1;i++)
  {
       v.push_back(i);
  }
    if(n%2==1)
    {
        v.push_back(0);
    }
    for(int i=1;i<=n1;i++)
    {
     v.push_back(i);
    }
  
    for(int i=0;i<n;i++)
    cout<<v[i]<<" ";
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
     cin>>arr[i];   
    }
    targetZero(arr,n);
}
