#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
int longestConsecutiveSubsequence(int arr[],int n)
{   unordered_map<int,int> mp;
int l=0,max_len=0;
   
    for(int i=0;i<n;i++)
    {int len1=0,len2=0;
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
        mp[arr[i]-len1]=len1+len2+1;
        if(mp.find(arr[i]+len2) !=mp.end())
        mp[arr[i]+len2]=len1+len2+1;
        cout<<"mp["<<arr[i]<<"] =  "<<len1+len2+1<<endl;
         cout<<"mp["<<arr[i]-len1<<"] = "<<len1+len2+1<<endl;
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
