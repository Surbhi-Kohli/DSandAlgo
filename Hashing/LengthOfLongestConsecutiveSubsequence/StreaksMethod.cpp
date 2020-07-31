/*
Input:
8
14 5 1 2 8 13 15 12

Output:
14 is the element under consideration
left boundary existed 14
right boundary existed 14
mp[14] =  1
5 is the element under consideration
left boundary existed 5
right boundary existed 5
mp[5] =  1
1 is the element under consideration
left boundary existed 1
right boundary existed 1
mp[1] =  1
2 is the element under consideration
left boundary existed 1
right boundary existed 2
mp[2] =  2
8 is the element under consideration
left boundary existed 8
right boundary existed 8
mp[8] =  1
13 is the element under consideration
left boundary existed 13
right boundary existed 14
mp[13] =  2
15 is the element under consideration
left boundary existed 13
right boundary existed 15
mp[15] =  3
12 is the element under consideration
left boundary existed 12
right boundary existed 15
mp[12] =  4
4
The max length consecutive subsequence for the above array is 4
Time Complexity - O(n)
Space Complexity - O(n)
*/


#include <iostream>
#include <unordered_map>
#include <algorithm> 
using namespace std;
int longestConsecutiveSubsequence(int arr[],int n)
{ 
    unordered_map<int,int> mp;
    int l=0,max_len=0;
   
    for(int i=0;i<n;i++)
    {  int len1=0,len2=0;
       cout<<arr[i]<<" is the element under consideration"<<endl;
        if(mp.find(arr[i]+1)!=mp.end())
        {
            len2=mp[arr[i]+1];
        }
        if(mp.find(arr[i]-1)!=mp.end())
        {
            len1=mp[arr[i]-1];
        }
        mp[arr[i]]=len1+len2+1;
        if(mp.find(arr[i]-len1)!=mp.end())
        {
             mp[arr[i]-len1]=len1+len2+1;
             cout<<"left boundary existed "<<arr[i]-len1<<endl;
        }
       
        if(mp.find(arr[i]+len2) !=mp.end())
        {
             mp[arr[i]+len2]=len1+len2+1;
             cout<<"right boundary existed "<<arr[i]+len2<<endl;
        }
       
        cout<<"mp["<<arr[i]<<"] =  "<<len1+len2+1<<endl;
       //  cout<<"mp["<<arr[i]-len1<<"] = "<<len1+len2+1<<endl;
        max_len=max(max_len,mp[arr[i]]);
    }
    
    return max_len;
    
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	cout<<longestConsecutiveSubsequence(arr,n);
	return 0;
}
