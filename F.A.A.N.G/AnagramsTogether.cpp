/*
#F@ANG
Given an array of strings, group anagrams together.
Note:All inputs will be in lowercase.
The order of your output does not matter.

Input Format
First line contains integer n as size of String array. Second line contains n strings.

Constraints
None

Output Format
Print the anagrams together.

Sample Input
6
eat
tea
tan
ate
nat
bat
Sample Output
eat tea ate 
bat 
tan nat

Time Complexity: O(NKlogK),where K=length of max length string,N=no. of strings(6 here in above input)
*/
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin>>n;
	string arr[n];
  unordered_map<string,vector<string>> mp;
  for(int i=0;i<n;i++)
  {
	  cin>>arr[i];
  }
  for(int i=0;i<n;i++)
  {   string orig=arr[i];
	  sort(arr[i].begin(),arr[i].end());
    mp[arr[i]].push_back(orig);
  }
  

  for(auto p:mp)
  {
	 // sort(p.second.begin(),p.second.end());
	  for(auto l:p.second)
	  {
		  cout<<l<<" ";
	  }
	  cout<<endl;
  } 

	return 0;
}
