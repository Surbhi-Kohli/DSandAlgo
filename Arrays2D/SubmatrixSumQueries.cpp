/*
Submatrix Sum Queries
Given a matrix of size M x N, there are large number of queries to find submatrix sums. Inputs to queries are left top and 
right bottom indexes of submatrix whose sum is to find out.

How to preprocess the matrix so that submatrix sum queries can be performed in O(1) time.

Input:                      Output:38
4 5                                11
1 2 3 4 6                          38
5 3 8 1 2
4 6 7 5 5 
2 4 8 9 4 
3
2 2 3 4 
0 0 1 1
1 2 3 3

*/
#include <iostream>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
   // cout<<"n is "<<n<<" and m is "<<m<<endl;
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
    int prefix[n][m]={0};
    for(int i=0;i<n;i++)
    {
        prefix[i][0]=arr[i][0];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
           prefix[i][j]=prefix[i][j-1]+arr[i][j]; 
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=1;i<n;i++)
        {
            prefix[i][j]=prefix[i-1][j]+prefix[i][j];
        }
    }
    int q;
    cin>>q;
   // cout<<q<<" is q"<<endl;
    while(q--)
    {
        int ti,tj,bi,bj;
        int sum=0;
        cin>>ti>>tj>>bi>>bj;
     
        if(ti!=0 && tj!=0)
        sum=prefix[bi][bj]-prefix[ti-1][bj]-prefix[bi][tj-1]+prefix[ti-1][tj-1];
        else if(ti!=0 && tj==0)
          sum=prefix[bi][bj]-prefix[ti-1][bj];
         else if(ti==0 && tj!=0)
          sum=prefix[bi][bj]-prefix[bi][tj-1];
          else
          sum=prefix[bi][bj];
          cout<<sum<<endl;
          
    }
    
	return 0;
}
