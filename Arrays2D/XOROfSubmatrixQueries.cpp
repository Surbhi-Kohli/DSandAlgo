/*  #Google
Given an N * N matrix and q queries, each containing position of top-left and bottom-right corner of a rectangular sub-matrix,
the task is to find the xor of all the elements from this sub-matrix.
A simple solution is to find the XOR of the entire sub-matrix for each query. Thus, the worst case time complexity for each query will be O(n2).

Efficient Approach: We are all familiar with the idea of prefix XOR on linear array i.e.

if arr[] = {1, 2, 3, 4} and we calculate prefixXOR[] = {1, 3, 0, 4} where prefixXOR[i] stores the XOR of values from arr[0] to arr[i]
Then the XOR of sub-array arr[i] to arr[j] can be found as prefixXOR[j] ^ prefixXOR[i – 1]
For example, the XOR of sub-array {2, 3} will be XOR(0, 1) = 1
This is because in the prefixXOR values for {1, 2, 3} and {1}, the value 1 got repeated twice which will give 0 as the XOR result
and will not affect the value of the other XOR operations.

We will try to extend the same to the 2-D matrix. We will compute a prefix-XOR matrix which will help us in solving each query in O(1).
In this case, our prefix-XOR matrix at position (R, C) will store the XOR of the rectangular sub-matrix with top-left corner at(0, 0) 
and bottom-right corner at (R, C).
We calculate the prefix-XOR in two steps.

Calculate the prefix-XOR for each row of the original matrix from left to right.
On the above matrix, calculate the prefix XOR for each column from top to bottom.
Once, we have the required prefix XOR-matrix, we can answer the queries with simplicity. 
XOR of a sub-matrix from (R1, C1) to (R2, C2) can be computed as prefix_xor[R2][C2] ^ prefix_xor[R1 – 1][C2] ^ prefix_xor[R2][C1 – 1] ^ prefix_xor[R1 – 1][C1 – 1].

Note: If R1 or C1 equals 0, then R1 – 1 or C1 – 1 should also be 0.

Input:
2
21 2 14 5 
2
0 1 1 1
0 0 1 1
Output:
7
28
*/
#include <iostream>
using namespace std;

void precomputXor(int **arr,int n,int **xorOfEntireSubmatrix)
{
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(j==0)
             xorOfEntireSubmatrix[i][j]=arr[i][j];
             else{
                 xorOfEntireSubmatrix[i][j]=xorOfEntireSubmatrix[i][j-1]^arr[i][j];
             }
         }
     }
     for(int j=0;j<n;j++)
     {
         for(int i=1;i<n;i++)
         {
             xorOfEntireSubmatrix[i][j]=xorOfEntireSubmatrix[i-1][j]^xorOfEntireSubmatrix[i][j];
         }
     }
     
}
int findXorOfSubmatrix(int **xorOfEntireMatrix,int x,int y,int a,int b){
    int xor1=0;
    int xor2=0;
    int xor3=0;
    if(x!=0)
    {
        xor1=xorOfEntireMatrix[x-1][b];
    }
    if(y!=0)
    xor2=xorOfEntireMatrix[a][y-1];
    if(x!=0 && y!=0)
    xor3=xorOfEntireMatrix[x-1][y-1];
    
    return (xorOfEntireMatrix[a][b]^xor1)^(xor2^xor3);
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int x,y,a,b;
  int **arr=new int*[n];
  
  for(int i=0;i<n;i++)
  {
      arr[i]=new int[n];
  }
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
          cin>>arr[i][j];
      }
  }
  int **xorOfEntireSubmatrix=new int*[n];
    for(int i=0;i<n;i++)
    {
        xorOfEntireSubmatrix[i]=new int[n];
    }
    precomputXor(arr,n,xorOfEntireSubmatrix);
  int queries;
  cin>>queries;
    while(queries--)
    {
        cin>>x>>y>>a>>b;
      cout<<findXorOfSubmatrix(xorOfEntireSubmatrix,x,y,a,b)<<endl;
      
    }
   
	return 0;
}
