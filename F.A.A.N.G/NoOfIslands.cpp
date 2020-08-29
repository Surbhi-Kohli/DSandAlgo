/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent
lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Input Format
First line contains two integers m and n denoting rows and columns of the grid map respectively. Following m lines contains n characters each '1' or '0'.

Constraints
None

Output Format
An integer denoting the number of distinct islands.

Sample Input
4 5
11000
11000
00100
00011
Sample Output
3


*/
#include<iostream>
#include <vector>
using namespace std;
void dfs(vector<vector<char>> &vec,int i,int j,int m,int n)
{
 if (i < 0 || i >= m || j < 0 || j >= n || vec[i][j] == '0') return;
	vec[i][j]='0';
	dfs(vec,i,j-1,m,n);
	dfs(vec,i,j+1,m,n);
	dfs(vec,i-1,j,m,n);
	dfs(vec,i+1,j,m,n);
}
int noOfIslands(vector<vector<char>> vec,int m,int n)
{  
  
    int count=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(vec[i][j]=='1')
			{  
				dfs(vec,i,j,m,n);
                count++;
			}
		}
	}
	return count;
}
int main() {

	int m,n;
    cin>>m>>n;

	vector<vector<char>> vec(m,vector<char> (n));
	for(int i=0;i<m;i++)
	{
      for(int j=0;j<n;j++)
	  {
		  cin>>vec[i][j];
	  }
	}

	cout<<noOfIslands(vec,m,n);

	return 0;
}
