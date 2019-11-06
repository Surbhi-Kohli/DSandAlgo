/*
ARRAYS-TARGET SUM TRIPLETS
Take as input N, the size of array. Take N more inputs and store that in an array.
Take as input “target”, a number. 
Write a function which prints all triplets of numbers which sum to target.

Input Format:First line contains input N. Next N lines contains the elements of array and N+1 line contains target number.

Constraints:
Length of Array should be between 1 and 1000.

Output Format
Print all the triplet present in  the array.

Sample Input
9
5
7
9
1
2
4
6
8
3
10
Sample Output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5

O(n^2)

*/
#include<iostream>
#include<algorithm>
using namespace std; 

// function to print triplets with given sum 
void findTriplets(int arr[], int n, int sum) 
{ 
	// sort array elements 
	sort(arr, arr + n); 

	for (int i = 0; i < n - 1; i++) { 
		// initialize left and right 
		int l = i + 1; 
		int r = n - 1; 
		int x = arr[i]; 
		while (l < r) { 
			if (x + arr[l] + arr[r] == sum) { 
				// print elements if it's sum is given sum. 
			cout<<x<<", "<<arr[l]<<" and "<<arr[r]<<endl; 
				l++; 
				r--; 
			} 

			// If sum of three elements is less 
			// than 'sum' then increment in left 
			else if (x + arr[l] + arr[r] < sum) 
				l++; 

			// if sum is greater than given sum, then 
			// decrement in right side 
			else
				r--; 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int targetSum;
	cin>>targetSum;
	findTriplets(arr, n, targetSum); 
	return 0; 
} 
