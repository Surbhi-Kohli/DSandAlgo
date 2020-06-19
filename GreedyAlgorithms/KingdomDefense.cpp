/*   

Theodre implements a new strategy game 'Defense of a Kingdom'.On each level,a player defends the kingdom that is represented by
a rectangular grid of cells.The player builds crossbow towers in some cells of the grid.The tower defends all the cells  in the
same row and in same column.No two towers share a row or col.

The penalty of the position is the number of cells in the largest undefended rectangle.Help Theodre write a program that
calculates the penalty of the given position.

Input:The first line of the input contains the number of test cases.Each test case consist of a line with 3 int numbers 
,w-width of the grid,h-height of the grid,n-no. of crossbow towers.Each of the following n lines containes 2 integer 
numbers xi and yi-the coordinates of the cell occupied by a tower 
Constraints: 1<=w,h<=40000 , 0<=n<=min(w,h)
1<=xi<=w, 1<=yi<=h

Output
For each test case,output a single integer number-the no of cells in the largest rectangle that is not defended by the towers


for input:
1
15 8 3
3 8
11 2
8 6
output:12
*/



#include <iostream>
#include <algorithm>
using namespace std;

int main() {
int t;
int w,h,n;
cin>>t;
int x[40010],y[40010];
  
  while(t--)
  {
      cin>>w>>h>>n;
      for(int i=0;i<n;i++)
      {
          cin>>x[i]>>y[i];
      }
      //sorting
      sort(x,x+n);
      sort(y,y+n);
      
      //delta x n delta y

    int dx=x[0]-1;
    int dy=y[0]-1;
    for(int i=1;i<n;i++)
    {
        dx=max(dx,x[i]-x[i-1]-1);
        dy=max(dy,y[i]-y[i-1]-1);
    }
    dx=max(dx,w-x[n-1]);
    dy=max(dy,h-y[n-1]);
    cout<<dx*dy<<endl;
  }

	return 0;
}
