/* You are given an array, A, of n elements. You have to remove exactly n/2 elements from array A, and add 
it to another array B(initially empty). After these operations, you can rearrange the elements of both the
arrays in any order. We define, difference between these two arrays as :
summationOf(abs(Ai-Bi))  where i goes from 1 to n/2
Find the maximum and minimum values of differences of these two arrays.

Input Format
First Line contains number of test cases, T. For each test case, first line contains a single integer, n (n is even).
Next line contains n integers, denoting the elements f array, A.

Constraints
1<=T<=10
1<=n<=10^5
|Ai|<=10^9

Output Format
For each test case, print the minimum and maximum value of differences between two arrays.

Sample Input
1
4
12 -3 10 0
Sample Output
5 25 

Sample Input 2
1
10
746113975
-349360348
729136705
644545866
906164083
973748660
-216604078
-646300889
-377059304
-351182282
Output:
1216775310 5940216190
Approach
There is a very simple approach to this question. Minsum is obtained when adjacent elements are present 
in different arrays. And maxsum is obtained when after sorting first n/2 element remain in array a sorted
in ascending order and last n/2 elements in array b sorted in descending order then take the difference
of both these arrays to get maxsum.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--)
	{  int max_sum=0;
	int min_sum=0;
		cin>>n;
       int arr[n];
	   for(int i=0;i<n;i++)
	   {
		   cin>>arr[i];
	   }
	   sort(arr,arr+n);
	   int arr2[n/2];
	   int k=0;
	   for(int i=n/2;i<n;i++)
	   {
		   arr2[k++]=arr[i];
	   }
      for(int i=0;i<n/2;i++)
      {
        if(arr[i]>arr2[i])
		{
			max_sum=max_sum+(arr[i]-arr2[i]);
		}
		else
		{
				max_sum=max_sum+(arr2[i]-arr[i]);
		}

      }
	  int k=0;
	  for(int i=1;i<n;i+=2)
	  {
		  arr2[k++]=arr[i];
	  }
	  

	}
	return 0;
}
