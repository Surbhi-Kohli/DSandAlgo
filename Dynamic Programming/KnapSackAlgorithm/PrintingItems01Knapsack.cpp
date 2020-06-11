/*
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value
in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and 
weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out 
the items such that sum of the weights of those items of given subset is smaller than or equal to W. You cannot break an
item, either pick the complete item, or don’t pick it (0-1 property).

Input : val[] = {60, 100, 120};
        wt[] = {10, 20, 30};
        W = 50;
Output : 220 //maximum value that can be obtained
         30 20 //weights 20 and 30 are included. 

Input : val[] = {40, 100, 50, 60};
        wt[] = {20, 10, 40, 30};
        W = 60;
Output : 200
         30 20 10
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
   int res = K[n][W]; 
    w = W; 
    for (i = n; i > 0 && res > 0; i--) { 
        
          // the item is included. 
        if (res == K[i - 1][w])  
            continue;         
        else { 
  
            // This item is included. 
            cout<<"Item with weight "<<wt[i - 1]<<" is included"<<endl; 
              
            // Since this weight is included its  
            // value is deducted 
            res = res - val[i - 1]; 
            w = w - wt[i - 1]; 
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
