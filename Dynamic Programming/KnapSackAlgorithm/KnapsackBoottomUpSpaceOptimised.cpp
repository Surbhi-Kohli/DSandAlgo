/*
If we observe carefully,we see that dp solution with states (i,j) will depend on state (i-1,j) or (i-1,j-wt[i-1]).
In either case the solution for state (i,j) will lie in the i-1th row of the memoization table.SO at every iteration
of the index,we can copy the values of the current row and use only this row for building the solution in next iteration 
and no other row will be used.Hence at any iteration we will be using only a single row to build the solution for
current row.Hence we can reduce the space complexity to just O(W)
Time complexity-O(N*W)
*/


#include <iostream>
using namespace std;
int knapSack(int val[],int wt[],int W, int n) 
{ 
    int i, w; 
    int K[2][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[1][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[1][w] = max( 
                    val[i - 1] + K[0][w - wt[i - 1]], 
                    K[0][w]); 
            else
                K[1][w] = K[i - 1][w]; 
        } 
      for(int j=0;j<=W;j++)
       {
        K[0][j]=K[1][j];
        }
    } 
  
  
    return K[1][W]; 
} 
int main() {
   int n,W;
  cin>>n;
  int val[n];
  int wt[n];
  for(int i=0;i<n;i++)
  {
      cin>>val[i];
  }
  for(int i=0;i<n;i++)
  {
      cin>>wt[i];
  }
  cin>>W;
  
       
  cout<<knapSack(val,wt,W,n);
  return 0;
}
