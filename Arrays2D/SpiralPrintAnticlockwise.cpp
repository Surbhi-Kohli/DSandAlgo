/*
Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers separated by commas with 'END' written in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
Explanation
For spiral level anti-clockwise traversal, Go for first column-> last row ->last column-> first row and then 
do the same traversal for the remaining matrix .

*/
#include<iostream>
using namespace std;
int main() {
    int m,n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    int rlo=0,rhi=m-1;
    int jlo=0,jhi=n-1;
    while(rlo<=rhi && jlo<=jhi)
    { //print first col
       for(int i=rlo;i<=rhi;i++)
       cout<<arr[i][jlo]<<", ";
       jlo++;
        
        //print last row
        for(int k=jlo;k<=jhi;k++)
        cout<<arr[rhi][k]<<", ";
        rhi--;
        //print last column,but check condition b4
        if(jlo<=jhi)
        {
            for(int k=rhi;k>=rlo;k--)
            cout<<arr[k][jhi]<<", ";
            jhi--;
        }
        //print first row,but check conditiion b4
        if(rlo<=rhi)
        {
             for(int k=jhi;k>=jlo;k--)
            cout<<arr[rlo][k]<<", ";
            rlo++;
        }
    }
    cout<<"END";
	return 0;
}
