/*
Approach 2-Store all array elements in a set .Find out the max-element and min-element of the array.Loop for i from min-element to max-element 
and keep checking if that i is present in set or not.If consecutive i is present,incremnt l.Find max of l,every time consecutive series breaks.
Time complexity= O(max-min).Although the complexity looks linear ,but this can take lot of time if numbers are not evenly distributed in range [max,min]
and if diff in max n in is large.
*/


#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int longestConsecutiveSubsequence(int arr[],int n)
{   set<int> st;
int l=0,max_len=0;
    int max=*max_element(arr,arr+n);
    int min=*min_element(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        st.insert(arr[i]);
    }
    for(int i=min;i<=max;i++)
    {
     if(st.find(i)!=st.end())
     {
         l++;

     }
     else{
         if(l>max_len)
         max_len=l;
         
         l=0;
     }
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
	
