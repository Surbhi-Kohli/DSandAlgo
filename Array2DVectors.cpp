/*
A 2D vector is a vector of vector. Like 2D arrays, we can declare and assign values to 2D matrix
*/
// C++ code to demonstrate 2D vector 
#include <iostream> 
#include <vector> // for 2D vector 
using namespace std; 

int main() 
{ 
	// Initializing 2D vector "vect" with 
	// values 
	vector<vector<int> > vect{ { 1, 2, 3 }, 
							{ 4, 5, 6 }, 
							{ 7, 8, 9 } }; 

	// Displaying the 2D vector 
	for (int i = 0; i < vect.size(); i++) { 
		for (int j = 0; j < vect[i].size(); j++) 
			cout << vect[i][j] << " "; 
		cout << endl; 
	} 

	return 0; 
} 
/* Like Java’s jagged arrays, each row of 2D vector can contain different number of columns.*/

#include <iostream> 
#include <vector> // for 2D vector 
using namespace std;   
int main() 
{ 
    // Initializing 2D vector "vect" with 
    // different number of values in each 
    // row. 
    vector<vector<int> > vect{ { 1, 2 }, 
                               { 4, 5, 6 }, 
                               { 7, 8, 9, 10 } }; 
  
    // Displaying the 2D vector 
    for (int i = 0; i < vect.size(); i++) { 
        for (int j = 0; j < vect[i].size(); j++) 
            cout << vect[i][j] << " "; 
        cout << endl; 
    } 
  
    return 0; 
} 

/***  Suppose we want to create a 2D vector of N rows and M column, and input values.  */
#include<bits/stdc++.h> 
using namespace std; 

int main(){ 
	int n = 4; 
	int m = 5; 

	// Create a vector containing n 
	//vectors of size m. 
	vector<vector<int> > vec( n , vector<int> (m)); //side note:If u want to initialize the 2D vector with 0's,then write as           
                                                   // vector<vector<int>>vec(n,vector<int>(m,0));

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++){ 
			vec[i][j] = j + i + 1; 
		} 
	} 

	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < m; j++){ 
			cout<< vec[i][j]<< " "; 
		} 
		cout<< "\n"; 
	} 

return 0; 
} 
/*  Exercise Problem : Define the 2D vector with different sizes of column input by user.  */
// CPP program to create a 2D vector where 
// every row has 
#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	// size of row 
	int row = 5; 
	int colom[] = { 5, 3, 4, 2, 1 }; 

	// Create a vector of vector with size 
	// equal to row. 
	vector<vector<int> > vec(row); 

	for (int i = 0; i < row; i++) { 

		// size of column 
		int col; 
		col = colom[i]; 

		// declare the i-th row to size of column 
		vec[i] = vector<int>(col); 
		for (int j = 0; j < col; j++) 
			vec[i][j] = j + 1; 
	} 

	for (int i = 0; i < row; i++) { 
		for (int j = 0; j < vec[i].size(); j++) 
			cout << vec[i][j] << " "; 
		cout << endl; 
	} 
} 
