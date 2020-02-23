/*
 There is a built-in function in C++ STL by the name of sort().

std::sort() is a generic function in C++ Standard Library, for doing comparison sorting.

Syntax:
sort(startaddress, endaddress, comparator)

where:
startaddress: the address of the first element of the array
endaddress: the address of the last element of the array
comparator: the comparison to be done with the array. 
            This argument is optional.
            
 Time Complexity
Best Case – O(N log N)
Average Case- O(N log N)
Worse Case- O(N log N)
where, N = number of elements to be sorted.

The algorithm used by sort() is IntroSort. Introsort being a hybrid sorting algorithm uses three sorting algorithm to minimise the running time, Quicksort, Heapsort and Insertion Sort. Simply putting, it is the best sorting algorithm around. It is a hybrid sorting algorithm, which means that it uses more than one sorting algorithms as a routine.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int a[]={1,5,4,3,2,6,8,-1};
    int n=sizeof(a)/sizeof(int);
    sort(a,a+n);
    for(int i=0;i<n;i++)
    {
       cout<<a[i]<<" ";  //-1 1 2 3 4 5 6 8
    }
	return 0;
}
/*********************************/
/*   How to sort in descending order?
sort() takes a third parameter that is used to specify the order in which elements are to be sorted. We can pass “greater()” function to sort in descending order. This function does a comparison in a way that puts greater element before. */


// C++ program to demonstrate descending order sort using 
// greater<>(). 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    sort(arr, arr+n, greater<int>()); 
  
    cout << "Array after sorting : \n"; 
    for (int i = 0; i < n; ++i) 
        cout << arr[i] << " "; 
  
    return 0; 
} 
