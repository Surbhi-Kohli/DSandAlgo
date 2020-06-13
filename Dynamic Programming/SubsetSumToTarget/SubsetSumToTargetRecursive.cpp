/*
Subset Sum Problem | DP-25
Given a set of non-negative integers, and a value sum, determine if there is a subset of the
given set with sum equal to given sum.

Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.

Approach: For the recursive approach we will consider two cases.
1. Consider the last element and now the required sum = target sum – value of ‘last’ element and
number of elements = total elements – 1
2. Leave the ‘last’ element and now the required sum = target sum and number of elements = total elements – 1


Complexity Analysis: The above solution may try all subsets of given set in worst case. Therefore time complexity
of the above solution is exponential. The problem is in-fact NP-Complete 
(There is no known polynomial time solution for this problem).

For Input:                  Output:Yes
6
3 34 4 12 5 2
9

*/

#include <iostream>
using namespace std;
bool subsetSumToTarget(int arr[],int n,int sum)
{
    if(sum==0)
    return true;
    if(n==0 && sum!=0)
    return false;
    if(arr[n-1]>sum)
    {
        return subsetSumToTarget(arr,n-1,sum);
    }
    bool op1=subsetSumToTarget(arr,n-1,sum);
    bool op2=subsetSumToTarget(arr,n-1,sum-arr[n-1]);
    return op1||op2;
    
    
}

int main() {

	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int sum;
	cin>>sum;
  
	bool ans=subsetSumToTarget(arr,n,sum);
	
	if(ans)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
