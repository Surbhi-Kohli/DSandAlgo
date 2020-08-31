/*

Given a 2D array of dimension r*c where each cell in the array can have values 0, 1 or 2 which has the following meaning: 0 : Empty cell 1 : Cells have fresh oranges 2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange
at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.

Input Format
The first line of input contains an integer T denoting the number of test cases.
Each test case contains two integers r and c, where r is the number of rows and c is the number of columns in the 
array arr and take r*c more inputs in an array arr.

Constraints
1 <= T <= 100
1 <= r <= 100
1 <= c <= 100
0 <= a[i] <= 2

Output Format
Print an integer which denotes the minimum time taken to rot all the oranges (-1 if it is impossible).

Sample Input
1
3 5
2 
1 
0 
2 
1 
1 
0 
1 
2 
1 
1 
0 
0 
2 
1
Sample Output
2

Below Implementation Time/Space Complexity
Complexity Analysis:
Time Complexity : O(max(R,C) * R *C).
The matrix needs to be traversed again and again until there is no change in the matrix, that can happen max(R,C) times. 
So time complexity is O(max(R,C) * R *C).
Space Complexity:O(1).
No extra space is required.

*/
#include <bits/stdc++.h> 
using namespace std; 

const int R = 3; 
const int C = 5; 

// Check if i, j is under the array limits of row and column 
bool issafe(int i, int j) 
{ 
	if (i >= 0 && i < R && j >= 0 && j < C) 
		return true; 
	return false; 
} 

int rotOranges(int v[R][C]) 
{ 
	bool changed = false; 
	int no = 2;
  int count=0;
	while (true) { 
       cout<<"entered while"<<endl;
     
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) { 

				// Rot all other oranges present at 
				// (i+1, j), (i, j-1), (i, j+1), (i-1, j) 
				if (v[i][j] == 2) { 
					if (issafe(i + 1, j) && v[i + 1][j] == 1) { 
						v[i + 1][j] = 2; 
						changed = true; 
					} 
					if (issafe(i, j + 1) && v[i][j + 1] == 1) { 
						v[i][j + 1] = 2; 
						changed = true; 
					} 
					if (issafe(i - 1, j) && v[i - 1][j] == 1) { 
						v[i - 1][j] = 2; 
						changed = true; 
					} 
					if (issafe(i, j - 1) && v[i][j - 1] == 1) { 
						v[i][j - 1] = 2; 
						changed = true; 
					} 
				} 
			} 
		} 
if(changed)
  count++;
		// if no rotten orange found it means all 
		// oranges rottened now 
		if (!changed) 
			break; 
		changed = false; 
		
      cout<<"count is "<<count<<endl;
	} 
  cout<<"count outside the while loop is "<<count<<endl;

	for (int i = 0; i < R; i++) { 
		for (int j = 0; j < C; j++) { 

			// if any orange is found to be 
			// not rotten then ans is not possible 
			if (v[i][j] == 1) 
				return -1; 
		} 
	} 

 
	return count; 
} 

// Driver function 
int main() 
{ 

	int v[R][C] =  {{2, 1, 0, 2, 1},
                  {1, 0, 1, 2, 1},
                  {1, 0, 0, 2, 1}}; 

	cout << "Max time incurred: " << rotOranges(v); 

	return 0; 
} 
