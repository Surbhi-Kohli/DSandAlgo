/*
Efficient Solution : For each element of the matrix, let us try to find the number of sub-matrices, the element will lie in.
This can be done in O(1) time. Let us suppose the index of an element be (X, Y) in 0 based indexing, then the number of submatrices (Sx, y) for 
this element will be in can be given by the formula Sx, y = (X + 1) * (Y + 1) * (N – X) * (N – Y) . Thus, for each element, ‘sum’ can be updated as sum += (Sx, y) * Arr(x, y).<-- from gfg

Every element will be part of more than submatrix and in each submatrix,it will be contributing something for the sum.Instead of finding all possible submatrices,we
can think in reverseorder and calculate the contribution of each element on the whole/final sum.
Contribution of each cell in final sum=element's value *(no. of submatrices this cell is part of).
To define a submatrix ,we need a pair of top left coordinates and bottom left coordinates.
No. of top left pairs=(i+1)*(j+1)
No. of bottom right pairs =(n-i)*(m-j)//and these submatrices will have our current element (i,j)
so sum=arr[i][j]*[(i+1)*(j+1)]*[(n-i)*(m-j)]

Time Complexity =O(n^2)
Space Complexity =O(1)


*/


#include <iostream>
using namespace std;
int sumOfAllSubMatrices(int **arr,int n,int m)
{
  
    int sum=0;
  
    for(int i=0;i<n;i++)
    {
        for(int j=0x;j<m;j++)
        {
           int tl=(i+1)*(j+1);
           int br=(n-i)*(m-j);
           sum+=(tl*br)*arr[i][j];
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
