/*
Stable Selection Sort
A sorting algorithm is said to be stable if two objects with equal or same keys appear in the same order in
sorted output as they appear in the input array to be sorted.
Any comparison based sorting algorithm which is not stable by nature can be modified to be stable by changing
the key comparison operation so that the comparison of two keys considers position as a factor for objects with 
equal key or by tweaking it in a way such that its meaning doesn’t change and it becomes stable as well.
Example:
Note: Subscripts are only used for understanding the concept.
Input : 4A 5 3 2 4B 1
Output : 1 2 3 4B 4A 5
Stable Selection Sort would have produced
Output : 1 2 3 4A 4B 5
Selection sort works by finding the minimum element and then inserting it in its correct position by swapping with
the element which is in the position of this minimum element. This is what makes it unstable.
Swapping might impact in pushing a key(let’s say A) to a position greater than the key(let’s say B) which are equal'
keys. which makes them out of desired order.
In the above example 4A was pushed after 4B and after complete sorting this 4A remains after this 4B. Hence resulting 
in unstability.
Selection sort can be made Stable if instead of swapping, the minimum element is placed in its position without 
swapping i.e. by placing the number in its position by pushing every element one step forward.
In simple terms use a technique like insertion sort which means inserting element in its correct place.
EXPLANATION WITH EXAMPLE:
Example: 4A 5 3 2 4B 1
         First minimum element is 1, now instead
         of swapping. Insert 1 in its correct place 
         and pushing every element one step forward
         i.e forward pushing.
         1 4A 5 3 2 4B
         Next minimum is 2 :
         1 2 4A 5 3 4B
         Next minimum is 3 :
         1 2 3 4A 5 3  2 4B
         Repeat the steps until array is sorted.
         1 2 3 4A 4B 5
*/
// C++ program for modifying Selection Sort 
// so that it becomes stable. 
#include <iostream> 
using namespace std; 

void stableSelectionSort(int a[], int n) 
{ 
	// Iterate through array elements 
	for (int i = 0; i < n - 1; i++) 
	{ 

		// Loop invariant : Elements till a[i - 1] 
		// are already sorted. 

		// Find minimum element from 
		// arr[i] to arr[n - 1]. 
		int min = i; 
		for (int j = i + 1; j < n; j++) 
			if (a[min] > a[j]) 
				min = j; 

		// Move minimum element at current i. 
		int key = a[min]; 
		while (min > i) 
		{ 
			a[min] = a[min - 1]; 
			min--; 
		} 
		a[i] = key; 
	} 
} 

void printArray(int a[], int n) 
{ 
	for (int i = 0; i < n; i++) 
		cout << a[i] << " "; 
	cout << endl; 
} 

// Driver code 
int main() 
{ 
	int a[] = { 4, 5, 3, 2, 4, 1 }; 
	int n = sizeof(a) / sizeof(a[0]); 
	stableSelectionSort(a, n); 
	printArray(a, n); 
	return 0; 
} 
