/*
Merge two binary Max Heaps
Given two binary max heaps as arrays, merge the given heaps.

Examples :

Input  : a = {10, 5, 6, 2}, 
         b = {12, 7, 9}
Output : {12, 10, 9, 2, 5, 7, 6}
The idea is simple. We create an array to store result. We copy both given arrays one by one to result.
Once we have copied all elements, we call standard build heap to construct full merged max heap.

Since time complexity for building the heap via downHeapify from array of n elements is O(n).
The complexity of merging the heaps is equal to O(n + m).

*/
// C++ program to merge two max heaps. 
#include <bits/stdc++.h> 
using namespace std; 

// Standard heapify function to heapify a 
// subtree rooted under idx. It assumes 
// that subtrees of node are already heapified. 
void maxHeapify(int arr[], int n, int idx) 
{ 
	// Find largest of node and its children 
	if (idx >= n) 
		return; 
	int l = 2 * idx + 1; 
	int r = 2 * idx + 2; 
	int max=idex; 
	if (l < n && arr[l] > arr[max]) 
		max = l; 
	
	if (r < n && arr[r] > arr[max]) 
		max = r; 

	// Put maximum value at root and 
	// recur for the child with the 
	// maximum value 
	if (max != idx) { 
		swap(arr[max], arr[idx]); 
		maxHeapify(arr, n, max); 
	} 
} 

// Builds a max heap of given arr[0..n-1] 
void buildMaxHeap(int arr[], int n) 
{ 
	// building the heap from first non-leaf 
	// node by calling max heapify function 
	for (int i = n / 2 - 1; i >= 0; i--) 
		maxHeapify(arr, n, i); 
} 

// Merges max heaps a[] and b[] into merged[] 
void mergeHeaps(int merged[], int a[], int b[], 
				int n, int m) 
{ 
	// Copy elements of a[] and b[] one by one 
	// to merged[] 
	for (int i = 0; i < n; i++) 
		merged[i] = a[i]; 
	for (int i = 0; i < m; i++) 
		merged[n + i] = b[i]; 

	// build heap for the modified array of 
	// size n+m 
	buildMaxHeap(merged, n + m); 
} 

// Driver code 
int main() 
{ 
	int a[] = { 10, 5, 6, 2 }; 
	int b[] = { 12, 7, 9 }; 

	int n = sizeof(a) / sizeof(a[0]); 
	int m = sizeof(b) / sizeof(b[0]); 

	int merged[m + n]; 
	mergeHeaps(merged, a, b, n, m); 

	for (int i = 0; i < n + m; i++) 
		cout << merged[i] << " ";  //12 10 9 2 5 7 6

	return 0; 
} 
