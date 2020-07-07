/*
Take as input N, the size of array. Take N more inputs and store that in an array. Take N more inputs and store that in another array.
Write a function which gives the intersection of two arrays in an ArrayList of integers and Print the ArrayList.

Input Format
First line contains N denoting the size of the two arrays. Second line contains N space separated integers denoting the elements of the first array.
Third line contains N space separated integers denoting the elements of the second array.

Constraints
Length of Arrays should be between 1 to 100000.

Output Format
Display the repeating elements in a comma separated manner enclosed in square brackets. The numbers should be sorted in increasing order.

Sample Input
7
1 2 3 1 2 4 1
2 1 3 1 5 2 2

Sample Output
[1, 1, 2, 2, 3]

Explanation
Check which integer is present in both the arrays and add them in an array .Print this array as the ans.

*/
#include <iostream>
#include <algorithm>
#include <map>
#include<vector>
using namespace std;


int main() {
	// your code goes here
	map<int,int> mp1;
	map<int,int> mp2; 
	int n;
	cin>>n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
	    	int x;
	    	cin>>x;
	    	mp1[x]++;
	}
	
	for(int i=0;i<n;i++)
	{
	    	int x;
	    	cin>>x;
	    	mp2[x]++;
	}

	
	for(auto p:mp1)
	{
	    if(mp2.find(p.first)!=mp2.end())
	    { 
	        int t=0;
	        if(mp2[p.first]<p.second)
	        {
	           t=mp2[p.first];
	         
	        }
	        else{
	             t=p.second;
	        }
	          while(t--)
	           {
	               arr.push_back(p.first);
	           }
	    }
	}
	cout<<"[";
	for(int i=0;i<arr.size()-1;i++)
	{
	    cout<<arr[i]<<", ";
	}
	cout<<arr[arr.size()-1];
	cout<<"]";
	return 0;
}
