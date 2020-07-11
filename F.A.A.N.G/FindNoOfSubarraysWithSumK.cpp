/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Input Format
First line contains input N.
Next line contains a single integer k
Third contains N space separated integers denoting the elements of the array.

Constraints
1<= N <=100000

Output Format
print Number of subarrays having sum exactly equal to k

Sample Input
4 
0
0 0 0 0 
Sample Output
10
Explanation
None

*/
#include<iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n,k;
	//int count=0;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
 unordered_map<int,int> mp;
        int count=0,pre=0;
        for(int i=0;i<n;i++)
        {
            pre+=arr[i];
            if(pre==k)
            {
                count++;
            }
            if(mp.find(pre-k)!=mp.end())
            {
                count+=mp[pre-k];
            }
            mp[pre]++;
        }
         cout<<count;
	return 0;
}
