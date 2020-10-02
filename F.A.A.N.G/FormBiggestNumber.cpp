/*
You are provided an array of numbers. You need to arrange them in a way that yields the largest value.

Input Format
First line contains integer t which is number of test case.
For each test case, you are given a single integer n in the first line which is the size of array A[] and next line contains n space separated integers denoting the elements of the array A .

Constraints
1<=t<=100
1<=m<=100
1<=A[i]<=10^5

Output Format
Print the largest value.

Sample Input
1
4
54 546 548 60
Sample Output
6054854654
Explanation
Upon rearranging the elements of the array , 6054854654 is the largest possible number that can be generated.

*/
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
	string x=to_string(a);
	string y=to_string(b);
	return x+y>y+x;
}
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		sort(arr,arr+n,cmp);
		int flag=0;
		for(int i=0;i<n;i++)
		{
          if(arr[i]!=0)
		  {
			  flag=1;
			  break;
		  }
		}
		string ans="";
		if(flag==1)
		{
          for(int i=0;i<n;i++)
		  {
			ans=ans+to_string(arr[i]);
		  }
		}
		else 
		ans="0";
		cout<<ans<<endl;
	}
	return 0;
}
