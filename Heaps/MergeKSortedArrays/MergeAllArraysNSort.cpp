// C++ program to merge k sorted arrays of size n each.
/*
Naive Approach: The very naive method is to create an output array of size n * k and then copy all the elements into the output array followed by sorting.

Algorithm:
Create a output array of size n * k.
Traverse the matrix from start to end and insert all the elements in output array.
Sort and print the output array.

Complexity Analysis:
Time Complexity :O(n*k).
Traversing the matrix requires O(n*k) time.
Space Complexity :O(n*k), The output array is of size n*k.
*/
#include<bits/stdc++.h> 
using namespace std; 
#define n 4 


// A utility function to print array elements 
void printArray(int arr[], int size) 
{ 
for (int i=0; i < size; i++) 
	cout << arr[i] << " "; 
} 

// This function takes an array of arrays as an argument and 
// All arrays are assumed to be sorted. It merges them together 
// and prints the final sorted output. 
void mergeKArrays(int arr[][n], int k, int output[]) 
{ 
	int c=0; 
	
	//traverse the matrix 
	for(int i=0; i<k; i++) 
	{ 
		for(int j=0; j<n ;j++) 
			output[c++]=arr[i][j]; 
	} 
	
	//sort the array 
	sort(output,output + n*k); 
	
} 


// Driver program to test above functions 
int main() 
{ 
	// Change n at the top to change number of elements 
	// in an array 
	int arr[][n] = {{2, 6, 12, 34}, 
					{1, 9, 20, 1000}, 
					{23, 34, 90, 2000}}; 
	int k = sizeof(arr)/sizeof(arr[0]); 
	
	int output[n*k]; 
	
	mergeKArrays(arr, 3, output); 

	cout << "Merged array is " << endl; 
	printArray(output, n*k); 

	return 0; 
} 
/*
Output:
Merged array is 
1 2 6 9 12 20 23 34 34 90 1000 2000


*/
