/*
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, 
and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that 
only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Input Format
First line contains an 4 integers i.e x1, y1, x2, y2 for rectangle 1, similarly second line contains coordinates for rectangle 2.

Constraints
None

Output Format
1 if rectangles overlap else 0.

Sample Input
0 0 1 1
1 0 2 1
Sample Output
0
A rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) are the coordinates of its bottom-left corner, and (x2, y2) are the coordinates of its top-right corner.

Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.

Given two (axis-aligned) rectangles, return whether they overlap.

Input Format
First line contains an 4 integers i.e x1, y1, x2, y2 for rectangle 1, similarly second line contains coordinates for rectangle 2.

Constraints
None

Output Format
1 if rectangles overlap else 0.

Sample Input
0 0 1 1
1 0 2 1
Sample Output
0
*/

#include<iostream>
using namespace std;
bool overlappingRectangles(int x0,int y0,int x1,int y1,int a0,int b0,int a1,int b1)
{
    if(x1<=a0||y0>=b1||x0>=a1||b0>=y1)//Conditions for rectangles not overlapping each other
    {
        return 0;
    }
    return 1;
}
int main(){
    int x0,y0,x1,y1;
    int a0,b0,a1,b1;
    cin>>x0>>y0>>x1>>y1;
    cin>>a0>>b0>>a1>>b1;
    cout<<overlappingRectangles(x0,y0,x1,y1,a0,b0,a1,b1);
}
