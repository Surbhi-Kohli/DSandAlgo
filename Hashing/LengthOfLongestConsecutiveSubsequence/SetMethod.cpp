/*
Input:
12
14 5 1 2 6 3 7 8 9 13 15 4
output:9
Time complexity: O(n).
Only one traversal is needed and the time complexity is O(n) under the assumption that set insert and search take O(1) time.
Auxiliary space : O(n).
To store every element in set O(n) space is needed.
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int longestConsecutiveSubsequence(int arr[],int n)
{   set<int> st;
int max_len=0;
   for(int i=0;i<n;i++)
   st.insert(arr[i]);
   int count=0;
    for(int i=0;i<n;i++)
    { 
        if(st.find(arr[i]-1)==st.end())
        {  count=1;
           int j=arr[i];
           while(st.find(j+1)!=st.end())
           {
               j++; 
               count++;
           }
          
        }
        max_len=max(count,max_len);
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
