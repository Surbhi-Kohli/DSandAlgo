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
    
    vector<vector<int> > vec( n , vector<int> (m));  
    int ans=hourglassSum(vec);
    cout<<ans;
    return 0;
    }
