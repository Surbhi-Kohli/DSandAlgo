/*
The heights of certain Buildings which lie adjacent to each other are given. Light starts falling from left side of the buildings.
If there is a building of certain Height, all the buildings to the right side of it having lesser heights cannot see the sun . 
The task is to find the total number of such buildings that receive light.

Input Format
First line contains the Number of Testcases T.
Next line contains the totalnumber of buildings
Next line contains the height of n buildings.

Constraints
1<=T<=100 1<=N<=100 1<=Hi<=100

Output Format
Print total Number of buildings that receive Light.

Sample Input
2
8
5 3 9 6 10 11 8 13
6
3 4 1 6 2 3
Sample Output
5
3

Sample Input 
1
7
5 2 5 6 4 3 7
Sample Output
4
 O(n)

*/
#include<iostream>
#include<climits>
using namespace std;
int main() {
	int t,n,count=0;
	int max_height=INT_MIN;
	cin>>t;
	while(t--)
	{
		count=0;
      cin>>n;
	  int arr[n];
	  for(int i=0;i<n;i++)
	  {
		  cin>>arr[i];
	  }
       count=1;
	   max_height=arr[0];
      for(int i=1;i<n;i++)
	  {
		  if(arr[i]>=max_height)//  >= is the condition and not > only
		  {
			  count++;
			  max_height=arr[i];
		  }
	  }
	  cout<<count<<endl;
	}
	return 0;  
}
