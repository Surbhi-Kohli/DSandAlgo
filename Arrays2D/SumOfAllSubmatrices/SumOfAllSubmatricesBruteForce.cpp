/*
Given a NxN 2-D matrix, the task to find the sum of all the submatrices.

Examples:

Input :2 2                      
       1 1 1 1
Output : 16
Explanation: 
Number of sub-matrices with 1 elements = 4
Number of sub-matrices with 2 elements = 4
Number of sub-matrices with 3 elements = 0
Number of sub-matrices with 4 elements = 1

Since all the entries are 1, the sum becomes
sum = 1 * 4 + 2 * 4 + 3 * 0 + 4 * 1 = 16

Input : 3 3                                      Input:   3 3
        1 2 3 4 5 6 7 8 9                                 1 1 1 1 1 1 1 1 1
Output : 500                                     Output:  100

Simple Solution: A naive solution is to generate all the possible submatrices and sum up all of them.
The time complexity of this approach will be O(n^6).


*/
#include <iostream>
using namespace std;
int sumOfAllSubmatricesBruteForce(int **arr,int n,int m)
{int sum=0;
    for(int ti=0;ti<n;ti++)
    {
        for(int tj=0;tj<m;tj++) ///generate top left corner of a submatrix with ti n tj
        {
            for(int bi=ti;bi<n;bi++)
            {
                for(int bj=tj;bj<m;bj++) //generate bottom right corner of a submatrix with bi n bj
                {
                    //iterate over the submatrix with topleft as (ti,tj) and bottom right as (bi,bj)
                    for(int row=ti;row<=bi;row++) 
                    {
                        for(int col=tj;col<=bj;col++)
                        {
                            sum+=arr[row][col];//accumulate sum
                        }
                    }
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
 cout<<sumOfAllSubmatricesBruteForce(arr,n,m);
	return 0;
}
