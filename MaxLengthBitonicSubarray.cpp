/*

You are provided n numbers of array. You need to find the maximum length of bitonic subarray. A subarray A[i … j] is biotonic if there is a k with i <= k <= j such that A[i] <= A[i + 1] … <= A[k] >= A[k + 1] >= .. A[j – 1] > = A[j] i.e subarray is first increasing and then decreasing or entirely increasing or decreasing.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of array and next line contains n space separated integers.

Constraints
1<=t<=100 1<=n<=1000000

Output Format
Print the maximum length.

Sample Input
2
6
12 4 78 90 45 23
4
40 30 20 10
Sample Output
5
4
Explanation
ForMaximum length = 4, 78, 90, 45, 23
*/
#include<iostream>
using namespace std;
int bitonic(int arr[], long long n)  
{  
    // Length of increasing subarray 
    // ending at all indexes  
    int inc[n];  
      
    // Length of decreasing subarray  
    // starting at all indexes  
    int dec[n];  
    int  max;  
  long long i;
    // length of increasing sequence  
    // ending at first index is 1  
    inc[0] = 1;  
  
    // length of increasing sequence 
    // starting at first index is 1  
    dec[n-1] = 1;  
  
    // Step 1) Construct increasing sequence array  
    for (i = 1; i < n; i++)  
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;  
  
    // Step 2) Construct decreasing sequence array  
    for (i = n-2; i >= 0; i--)  
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;  
  
    // Step 3) Find the length of 
    // maximum length bitonic sequence  
    max = inc[0] + dec[0] - 1;  
    for (i = 1; i < n; i++)  
        if (inc[i] + dec[i] - 1 > max)  
            max = inc[i] + dec[i] - 1;  
  
    return max;  
}  
int main() {
    int t;
    cin>>t;
    long long n;
    for(int i=0;i<t;i++)
   {
       cin>>n;
       int arr[n];
       for(long long j=0;j<n;j++)
       cin>>arr[j];
       cout<<bitonic(arr,n)<<endl;
   }
	return 0;
}
