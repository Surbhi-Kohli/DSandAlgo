/*
 we will discuss how to implement QuickSort using random pivoting. In QuickSort we first partition the 
 array in place such that all elements to the left of the pivot element are smaller, while all elements
 to the right of the pivot are greater that the pivot. Then we recursively call the same procedure for 
 left and right subarrays.

Unlike merge sort we don’t need to merge the two sorted arrays. Thus Quicksort requires lesser auxiliary 
space than Merge Sort, which is why it is often preferred to Merge Sort.Using a randomly generated pivot we 
can further improve the time complexity of QuickSort.
Using random pivoting we improve the expected or average time complexity to O (N log N). 
The Worst Case complexity is still O ( N^2 ).
In a non-randomized quick sort,the wost case occurs when the array is already sorted in  ascending/descending order.
Complexity will be O(n^2) [Here ppartition happens at one end]
best case complexity=O(nlogn) [When partition happens in the middle]
Average case= O(nlogn)
Given an array A, of N elements. Sort the array using quicksort algorithm.(Note : Use randomized quicksort,
otherwise worst case will not pass).

Input Format
A single integer, N, denoting the number of elements in array. Next line contains N integers, denoting the elements of array.

Constraints
1<=N<=2*10^5 |Ai|<=10^9

Output Format
Print in a single line, N spaced integers, denoting the elements of array A in sorted order.

Sample Input
5
3 6 4 1 2
Sample Output
1 2 3 4 6 

*/

#include <iostream>
#include <cstdlib>
using namespace std;


int partition(int arr[],int low,int high)
{
    int pivot=high;
    int i=low-1;
    for(int j=low;j<=high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return (i+1);//returns the correct position of the pivot element
}
//to select a random pivot
int partition_random(int arr[],int low,int high)
{
    //Generate a random number between low...high
    
    srand(time(NULL));//Giving current time as a seed to srand
    int random=low+rand()%(high-low);
    
    //Swap A[random] with A[high]
    swap(arr[random],arr[high]);
    return partition(arr,low,high);
}

void quickSort(int arr[],int s,int e)
{
    if(s>=e)
    return;
    int p=partition_random(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
    
}
int main() {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
quickSort(arr,0,n-1);
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
	return 0;
}
