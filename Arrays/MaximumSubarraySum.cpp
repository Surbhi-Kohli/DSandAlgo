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
void kadaneAlgo(int arr[],int n)
{
    int left=0,leftO=0,right=0,rightO=0;
    int curr_sum=arr[0];
    int max_sum=arr[0];
    for(int i=1;i<n;i++)
    {
        if(curr_sum+arr[i]>arr[i])
        {
            curr_sum+=arr[i];
            right=i;
        }
        else{
            curr_sum=arr[i];
            right=i;
            left=i;
        }
      
        if(curr_sum>max_sum)
        {  max_sum=max(curr_sum,max_sum);
           
            leftO=left;
            rightO=right;
        }
      //  cout<<max_sum<<endl;
    }
    cout<<max_sum<<" left index-> "<<leftO<<"  rightIndex-> "<<rightO;
    
}
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
	      kadaneAlgo(arr, n); 
  
    }   
       
    
    
	return 0;
}
