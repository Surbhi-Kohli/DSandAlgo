/*MAXIMUM SUBARRAY SUM
You are given a one dimensional array that may contain both positive and negative integers, find the sum of contiguous subarray of numbers which has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6}, then the maximum subarray sum is 7.

Input Format:
The first line consists of number of test cases T. Each test case consists of N followed by N integers.

Constraints:
1 <= N <= 100000

1 <= t <= 20

-100000000 <= A[i] <= 100000000

Output Format
The maximum subarray sum

Sample Input
2
4
1 2 3 4
3
-10 5 10
Sample Output
10
15*/
#include<iostream>
using namespace std;
int main() {
    int tc;
    cin>>tc;
    int n;
    for(int i=0;i<tc;i++)
    {
         cin>>n;
         int *arr=new int[n];
         for(int j=0;j<n;j++)
         cin>>arr[j];
         
         int csum=arr[0],maxsum=arr[0];
     for(int j=1;j<n;j++)
     {
         csum=(arr[j]>csum+arr[j])?arr[j]:(csum+arr[j]);
        
         maxsum=(csum>maxsum)?csum:maxsum;
     }
     cout<<maxsum<<endl;
    }
    
	return 0;
}
