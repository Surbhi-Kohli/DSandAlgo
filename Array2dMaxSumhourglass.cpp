
/*
Given a 2D matrix, the task is that we find maximum sum of a hour glass.
An hour glass is made of 7 cells
in following form.
    A B C
      D
    E F G
   Example:
   Input : 0 3 0 0 0
        0 1 0 0 0
        1 1 1 0 0
        0 0 2 4 4
        0 0 0 2 4
   Output : 11
   Below is the hour glass with
   maximum sum
1 0 0
  4
0 2 4

It is evident from definition of hour glass that number of rows and number of columns must be equal to 3. 
If we count total number of hour glasses in a matrix, we can say that the count is equal to count of possible
top left cells in hour glass. Number of top-left cells in a hour glass is equal to (R-2)*(C-2). 
Therefore, in a matrix total number of hour glass is (R-2)*(C-2)
*/


#include<bits/stdc++.h>
using namespace std;
int hourglassSum(vector<vector<int>> mat) {
int ss=mat.size();
//return ss;
 if (ss<3) 
        return -1; 
  
    // Here loop runs (ss-2)*(ss-2) times considering 
    // different top left cells of hour glasses. 
    int max_sum = INT_MIN; 
    for (int i=0; i<ss-2; i++) 
    { 
        for (int j=0; j<ss-2; j++) 
        { 
            // Considering mat[i][j] as top left cell of 
            // hour glass. 
            int sum = (mat[i][j]+mat[i][j+1]+mat[i][j+2])+ 
                      (mat[i+1][j+1])+ 
                  (mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2]); 
  
            // If previous sum is less then current sum then 
            // update new sum in max_sum 
            max_sum = max(max_sum, sum); 
        } 
    } 
    return max_sum;

}
int main(){ 
    int n; 
   cin>>n
    // Create a vector containing n  vectors of size n
    
    vector<vector<int> > vec( n , vector<int> (n));  
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>vec[i][j];
        }
    }
    int ans=hourglassSum(vec);
    cout<<ans;
    return 0;
    }
