/*Take as input a two-d array. Wave print it column-wise.

Input Format
Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

Constraints
Both M and N are between 1 to 10.

Output Format
All M * N integers seperated by commas with 'END' wriiten in the end(as shown in example).

Sample Input
4 4
11 12 13 14
21 22 23 24
31 32 33 34
41 42 43 44
Sample Output
11, 21, 31, 41, 42, 32, 22, 12, 13, 23, 33, 43, 44, 34, 24, 14, END
*/
#include <iostream>
#include<vector>
using namespace std;
void wavePrint(vector<vector<int>> v,int row,int col)
{
    //iterate over columns
    for(int j=0;j<col;j++)
    {
        //check for odd or even col
        if(j&1)
        {
            for(int i=row-1;i>=0;i--)
            cout<<v[i][j]<<" ";
        }
        else{
            for(int i=0;i<row;i++)
              cout<<v[i][j]<<" ";
        }
    }
    
}
int main() {
int row,col;
cin>>row>>col;
vector<vector <int>> vec(row,vector<int>(col));
for(int i=0;i<row;i++)
{
    for(int j=0;j<col;j++)
    {
        cin>>vec[i][j];
    }
}
wavePrint(vec,row,col);
	return 0;
}
