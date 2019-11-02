/*
ARRAYS-TARGET SUM PAIRS
Take as input N, the size of array. Take N more inputs and store that in an array.
Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format:
The first line contains input N. 
Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints:
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input      Sample Output
5                   1 and 4
1                   2 and 3
3
4
2
5
5

*/
#include<iostream>
#include<algorithm>//to use sort function
using namespace std;

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target=0;
    cin>>target;
   // int l=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
   int low=0,high=n-1;
   while(low<high)
   {
       if(arr[low]+arr[high]==target)
       {
       cout<<arr[low]<<" and "<<arr[high]<<endl;
       low++;
       high--;
       }
       else if(arr[low]+arr[high]>target)
       high--;
       else
       low++;
   }
    
	return 0;
}
