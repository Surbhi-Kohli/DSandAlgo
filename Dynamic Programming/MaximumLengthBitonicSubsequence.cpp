/*
Given an array arr[0 … n-1] containing n positive integers, a subsequence of arr[] is called Bitonic 
if it is first increasing, then decreasing. Write a function that takes an array as argument and returns
the length of the longest bitonic subsequence.

A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. Similarly,
decreasing order sequence is considered Bitonic with the increasing part as empty.

You are provided n numbers of array. You need to find the maximum length of biotonic subsequence.
A subsequence is biotonic if it is first strictly increasing and then strictly decreasing or entirely strictly increasing or strictly decreasing.
Examples:

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};
Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Input arr[] = {12, 11, 40, 5, 3, 1}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 12, 11, 5, 3, 1)

Input arr[] = {80, 60, 30, 40, 20, 10}
Output: 5 (A Longest Bitonic Subsequence of length 5 is 80, 60, 30, 20, 10)

Input Format
First line contains integer t which is number of test case.
For each test case, in the first line you are given an integer n which is the size of array and 
the next line contains n space separated integers denoting the elements of the array.

Constraints
1<=t<=100
1<=n<=1000
| Ai | <= 10000

Output Format
Print the maximum length of biotonic subsequence for each testcase in a new line.

Sample Input
2
8
1 11 2 10 4 5 2 1
6
80 60 30 40 20 10
Sample Output
6
5
Explanation
For 1st test case : Maximum length = 1, 2, 4, 5, 2, 1
For 2nd test case : Maximum length = 80, 60, 40, 20 10 or 80, 60, 30, 20 10



*/


#include <iostream>
#include<cstring>
using namespace std;
int solveBitonicLength(int arr[],int n)
{
    int left[n];
    int right[n];
    memset(left,1,n);
    memset(right,1,n);
    //We initialize left n right array by 1 as ,for each element ,length of subsequence will atleast be 1 ie there
    //will be the number itself in the subsequence ending at that element/number.
     for(int i=0;i<n;i++)
    {
        right[i]=1;
    }
   
    for(int i=0;i<n;i++)
    {  int x=1;
        for(int j=0;j<i;j++)
        {
            if(arr[j]<arr[i])
            {
                x=max(x,left[j]+1);
            }
        }
        left[i]=x;//left[i] gets count of elements smaller than arr[i] that are to the left of arr[i]
    }
    for(int i=n-2;i>=0;i--)
    {  
        int x=1;
        for(int j=n-1;j>i;j--)
        { //cout<<"arr[i] is "<<arr[i]<<" arr[j] is "<<arr[j]<<endl; 
            if(arr[j]<arr[i])
           {  ///cout<<"right[j] is "<<right[j]<<endl;
             x=max(x,right[j]+1);
          }
           
        }
        right[i]=x;//right[i] gets count of elements smaller than arr[i] that are to the right of arr[i]
       
    }
    int ans=0;
   
    for(int i=0;i<n;i++)
    {
        ans=max(ans,left[i]+right[i]-1); //we get max value of length for elements forming a bitonic subsequence
    }
    return ans;
    
}





int main() {
int t;
cin>>t;
int n;
while(t--)
{
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   cout<<solveBitonicLength(arr,n)<<endl;
}
	return 0;
}
