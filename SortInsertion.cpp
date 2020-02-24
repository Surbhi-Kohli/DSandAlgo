/*
Insertion Sort-
Best Case Complexity - O(N)->.Case in which the first remaining element of the input is only compared with the right-most element of the
sorted subsection of array.

Worst Case- O(n^2);
Auxiliary Space - O(1) [Insertion Sort is in place i.e only requires constant amoumt O(1) of additional memory]
So insertion sort is in-place 


Boundary Case:Insertion Sort takes minimum time to sort if elements are sorted in reverse order.And it takes minimum time(order of N) 
                when elements are already sorted.

Is insertion sort stable- Yes
Stability of a sorting algo-A sorting algo is said to be stable if 2 objects with equal keys appear in same order in sorted output as 
they appear in the input array to be sorted

Which other sorting algos are stable-Bubble sort,Insertion Sort,Merge Sort,Count Sort

Given an array A of size N , write a function that implements insertion sort on the array. Print the elements of sorted array.

Input Format
First line contains a single integer N denoting the size of the array. Next line contains
N space seperated integers where ith integer is the ith element of the array.

Constraints
1 <= N <= 1000
|Ai| <= 1000000

Output Format
Output N space seperated integers of the sorted array in a single line.

Sample Input
4
3 4 2 1
Sample Output
1 2 3 4
Explanation
For each test case, write insertion sort to sort the array.
*/
#include<iostream>
using namespace std;
int main() {
  int n;
  cin>>n;
  int arr[n];
  int key,j=0;
  for(int i=0;i<n;i++)
  cin>>arr[i];
  
 for(int i=1;i<6;i++)
  {
      key=arr[i];
      j=i-1;
     while(j>=0 && arr[j]>key)
     {
         arr[j+1]=arr[j];
         j--;
     }
     arr[j+1]=key;
  }
 
   for(int k=0;k<n;k++)
  cout<<arr[k]<<endl;
	return 0;
}
