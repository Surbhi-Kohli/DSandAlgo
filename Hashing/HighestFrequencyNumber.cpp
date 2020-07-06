/*

Given an array find the number which comes with maximum frequency. It must work in O(n) time complexity.

Input Format
Enter the size of the array N and add N more numbers and store in an array

Constraints
1 <= N <= 10^7

Output Format
Display the number with the maximum frequency.

Sample Input
5
1 2 2 2 3
Sample Output
2
Explanation
2 has the highest frequency in the array i.e. 3.


*/
#include<iostream>
#include<climits>
#include <unordered_map>
using namespace std;
int main() {
	long long int n;
	unordered_map<long long int,long long int> mp;
	cin>>n;
	long long int x;
	for(long long int i=0;i<n;i++)
	{   cin>>x;
	//cout<<" read "<<x<<endl;
             mp[x]++;
	}
long long int freq=INT_MIN;
int ans=0;
for(auto p:mp)
{
  if(p.second>freq)
  {
	  freq=p.second;
	  ans=p.first;
  }
}

cout<<ans;
	return 0;
}
