/*

Given a sorted array with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array. 
Note:- If the x is not found in the array, print -1 -1

Input Format
The first line contains two integers n and x. The second line contains n spaced integers.

Constraints
1<n <10^8
-1< arr[i]<10^9

Output Format
Print index of the first and last occurrences of the number x with a space in between.

Sample Input
9 7
1 3 5 5 5 5 7 123 125
Sample Output
6 6


Time Complexity of this method =O(2LogN)=O(LogN)
*/

#include <iostream>
using namespace std;
int findFirstOccurence(int arr[],int n,int x)
{
    int s=0,e=n-1;
    int f=-1;
    int mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(x==arr[mid])
        {
            f=mid;
            e=mid-1;
        }
        else if(x>arr[mid])
        {
           
            s=mid+1;
        }
        else{
              e=mid-1;
           
        }
    }
    return f;
}
int findLastOccurence(int arr[],int n,int x)
{
    int s=0,e=n-1;
    int l=-1;
    int mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(arr[mid]==x)
        {
            l=mid;
            s=mid+1;
        }
        else if(arr[mid]<x)
        {
            
              s=mid+1;
        }
        else
        {
            e=mid-1;
           
        }
    }
    return l;
}
int main() {
    int n,x;
    cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int f=findFirstOccurence(arr,n,x);
    int l=findLastOccurence(arr,n,x);
    cout<<f<<" "<<l;
}
