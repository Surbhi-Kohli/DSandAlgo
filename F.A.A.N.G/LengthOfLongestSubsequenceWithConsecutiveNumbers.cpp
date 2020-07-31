/*

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Input Format
First line contains single integer n.
Second line contains n integers Ai.

Constraints
1<=n<=1e5 1<=Ai<=1e6

Output Format
Single line containing single integer

Sample Input
6
100 4 200 1 3 2
Sample Output
4

*/
#include<bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSubsequence(int arr[],int n)
{
     set<int> s;
     int count=0,max_len=0;
     for(int i=0;i<n;i++)
     {
          s.insert(arr[i]);
     }
     for(int i=0;i<n;i++)
     {   count=1;
          if(s.find(arr[i]-1)==s.end())
          {
               int j=arr[i];
               while(s.find(j+1)!=s.end())
               {
                    j++;
                    count++;
               }
          }
          max_len=max(count,max_len);
     }
     return max_len;
}
int main(){
     int n;
     cin>>n;
     int arr[n];
     for(int i=0;i<n;i++)
     {
          cin>>arr[i];
     }
     cout<<lengthOfLongestConsecutiveSubsequence(arr,n);
     return 0;
}
