/*
Sum of all Submatrices of a Given Matrix
Given a NxN 2-D matrix, the task to find the sum of all the submatrices.

Examples:

Input :  2 2 
         1 1 1 1
Output : 16
Explanation: 
Number of sub-matrices with 1 elements = 4
Number of sub-matrices with 2 elements = 4
Number of sub-matrices with 3 elements = 0
Number of sub-matrices with 4 elements = 1

Since all the entries are 1, the sum becomes
sum = 1 * 4 + 2 * 4 + 3 * 0 + 4 * 1 = 16

Input : 3 3                      Input:3 3
        1 2 3 4 5 6 7 8 9           1 1 1 1 1 1 1 1 1 
Output : 500                      Output :100 


Time Complexity of the below  approach is O(n^4)
Space Complexity of the below approach is O(n^2)
*/
#include <iostream>
using namespace std;
int sumOfAllSubMatrices(int **arr,int n,int m)
{
    int prefix[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            prefix[i][j]=0;
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        prefix[i][0]=arr[i][0];
    }
    
  
    
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            prefix[i][j]=arr[i][j]+prefix[i][j-1];
        }
    }
   
    for(int j=0;j<m;j++)
    {
        for(int i=1;i<n;i++)
        {
            prefix[i][j]+=prefix[i-1][j];
        }
    }
    
    for(int ti=0;ti<n;ti++)
    {
        for(int tj=0;tj<m;tj++)
        {
            for(int bi=ti;bi<n;bi++)
            {
                for(int bj=tj;bj<m;bj++)
                { 
                    if(ti!=0 && tj!=0)
                    sum=sum+(prefix[bi][bj]-prefix[ti-1][bj]-prefix[bi][tj-1]+prefix[ti-1][tj-1]);
                    else if(ti==0 && tj!=0)
                    sum=sum+prefix[bi][bj]-prefix[bi][tj-1];
                    else if(tj==0 && ti!=0)
                    sum+=prefix[bi][bj]-prefix[ti-1][bj];
                    else
                    sum+=prefix[bi][bj];
                   
                }
            }
        }
    }
   
    return sum;
}
int main() {
    int n,m;
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
    cout<<sumOfAllSubMatrices(arr,n,m);
	
	return 0;
}
