/*  Given a matrix, print it in Reverse Wave Form.

Examples :

Input :  1  2  3  4
         5  6  7  8
         9  10 11 12
         13 14 15 16
Output : 4 8 12 16 15 11 7 3 2 6 10 14 13 9 5 1

Input :  1  9  4  10
         3  6  90 11
         2  30 85 72
         6  31 99 15 
Output : 10 11 72 15 99 85 90 4 9 6 30 31 6 2 3 1

Approach :To get the reverse wave form for a given matrix, we first print the elements of the last column of the matrix in downward direction then print the elements of the 2nd last column in the upward direction, then print the elements in third last column in downward direction and so on. 
matrix-reverse-wave-form*/
#include <iostream>
#include<vector>
using namespace std;
void wavePrint(vector<vector<int>> arr,int row,int col)
{
    //iterate over columns
  int i, j = col-1, wave = 1; 
  
    /* m     - Ending row index 
        n     - Ending column index 
        i, j     - Iterator 
        wave     - for Direction 
        wave = 1 - Wave direction down 
        wave = 0 - Wave direction up   */
    while (j >= 0) { 
          
        // Check whether to go in 
        // upward or downward 
        if (wave == 1) { 
              
            // Print the element of the matrix 
            // downward since the value of wave = 1 
            for (i = 0; i < row; i++)  
                cout << arr[i][j] << " ";   
            
            wave = 0; 
           
        } 
        else { 
              
            // Print the elements of the  
            // matrix upward since the value 
            // of wave = 0 
            for (i = row - 1; i >= 0; i--)  
                cout << arr[i][j] << " "; 
              
            wave = 1; 
           
        } 
	     j--; 
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
