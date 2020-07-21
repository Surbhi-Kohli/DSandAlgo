/*
Given an integer array with even length, where different numbers in this array represent different kinds of candies. Each number
means one candy of the corresponding kind. You need to distribute these candies equally in number to brother and sister. Print the maximum
number of kinds of candies the sister could gain.

Input Format
The first line contains an integer N, which denotes the Size of Arrays.and then next line contains n space separated
integers representing the values of Arrays

Constraints
1< N <10,001

Output Format
Print a Single Integer A which denotes kinds of candies the sister could gain.

Sample Input
6 
1 1 1 2 2 3 
Sample Output
3

Sample Input 
6
1 2 3 4 5 6
Sample Output
3
*/
#include<iostream>
#include<set>
using namespace std;
int main() {
	int n;
	cin>>n;
	int arr[n];
	set<int> st;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		st.insert(arr[i]);
	}
	int s=st.size();
	int other=n/2;
cout<<min(s,other);
	return 0;
}
