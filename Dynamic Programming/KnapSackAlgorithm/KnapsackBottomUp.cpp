/*
 In the Dynamic programming we will work considering the same cases as mentioned in the recursive approach.
 In a DP[][] table let’s consider all the possible weights from ‘1’ to ‘W’ as the columns and weights that 
 can be kept as the rows.
The state DP[i][j] will denote maximum value of ‘j-weight’ considering all values from ‘1 to ith’. So if
we consider ‘wi’ (weight in ‘ith’ row) we can fill it in all columns which have ‘weight values > wi’. Now 
two possibilities can take place:

Fill ‘wi’ in the given column.
Do not fill ‘wi’ in the given column.
Now we have to take a maximum of these two possibilities, formally if we do not fill ‘ith’ weight in ‘jth’ 
column then DP[i][j] state will be same as DP[i-1][j] but if we fill the weight, DP[i][j] will be equal to 
the value of ‘wi’+ value of the column weighing ‘j-wi’ in the previous row. So we take the maximum of these 
two possibilities to fill the current state.
*/

#include <iostream>
using namespace std;
int knapSack(int val[],int wt[],int W, int n) 
{ 
    int i, w; 
    int K[n + 1][W + 1]; 
  
    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) { 
        for (w = 0; w <= W; w++) { 
            if (i == 0 || w == 0) 
                K[i][w] = 0; 
            else if (wt[i - 1] <= w) 
                K[i][w] = max( 
                    val[i - 1] + K[i - 1][w - wt[i - 1]], 
                    K[i - 1][w]); 
            else
                K[i][w] = K[i - 1][w]; 
        } 
    } 
  
    return K[n][W]; 
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
