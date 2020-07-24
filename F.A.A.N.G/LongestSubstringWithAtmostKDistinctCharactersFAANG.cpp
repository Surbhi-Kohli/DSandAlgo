/*
Given a string, find the length of the longest substring T that contains at most k distinct characters.

Input Format
First line contain T test cases. The following T lines contains a String and a integer k each.

Constraints
The problem should be done in linear time.

Output Format
An integer value returning the the length.

Sample Input
1
eceba 3
Sample Output
4
Explanation
"eceb" is a substring of length 4 with 3 distinct characters.
*/
#include<iostream>
#include <unordered_map>
#include <climits>
using namespace std;
int longestSubstringWithKDistinctChars(string s,int k)
{   
    unordered_map<char,int> mp;
    int l=0,r=0;
    int len=0,max_len=0;
    mp[s[0]]=0;
    r++;
    len++;
    max_len=max(len,max_len);
   
    while(mp.size()<=k && r<s.size())
    {   
     
        if(mp.size()==k && mp.find(s[r])==mp.end())
        {
      
            int small=INT_MAX;
            char curr;
            for(auto it=mp.begin();it!=mp.end();it++)
            {
                if(it->second<small)
                {
                   small=it->second;
                   curr=it->first;
                }
                
            }
            mp.erase(curr);
            l=small+1;

        }
        mp[s[r]]=r;  
       
        len=r-l+1;
        max_len=max(len,max_len);
       
         r++;
    }
    return max_len;
}

int main(){
int t;
cin>>t;
while(t--)
{
    string s;
    int k;

    cin>>s;
   cin>>k;
   
   cout<<longestSubstringWithKDistinctChars(s,k);
}
    return 0;
}
