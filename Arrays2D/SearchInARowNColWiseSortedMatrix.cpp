/*

Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . Find if element x is present in the matrix or not.

Input Format
First line consists of two space separated integers N and M, denoting the number of element in a row and column respectively. Second line of each test
case consists of N*M space separated integers denoting the elements in the matrix in row major order. Third line of each test case contains a 

single integer x, the element to be searched.

Constraints
1 <= N,M <= 30 0 <= A[i] <= 100

Output Format
Print 1 if the element is present in the matrix, else 0.

Sample Input
3 3
3 30 38
44 52 54
57 60 69
62
Sample Output
0
Explanation
Search the element in the sorted matrix. If the element is present print 1 otherwise print 0. In the sample input,in first case 62
is not present in the matrix so 0 is printed. Similarly, for second case 55 is present in the matrix so 1 is printed.

Time Complexity of the below approach is O(m+n)
*/
#include<iostream>
using namespace std;
int matrixSearch(int **arr,int n,int m,int key)
{
	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(key==arr[i][j])
			{
				return 1;
			}
			else if(key<arr[i][j])
			continue;
			else{
				break;
			}

		}
	}
	return 0;
}
int main() {
	int n,m,key;
	cin>>n>>m;
	int **arr=new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[m];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>arr[i][j];
		}
	}
	cin>>key;
	cout<<matrixSearch(arr,n,m,key);
	return 0;
}
