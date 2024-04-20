## Find maximum (or minimum) sum of a subarray of size k

Given an array of integers and a number k, find maximum sum of a subarray of size k.

Examples :

Input  : arr[] = {100, 200, 300, 400}
         k = 2
Output : 700

Input  : arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20}
         k = 4 
Output : 39
We get maximum sum by adding subarray {4, 2, 10, 23}
of size 4.

Input  : arr[] = {2, 3}
         k = 3
Output : Invalid
There is no subarray of size 3 as size of whole
array is 2.
A Simple Solution is to generate all subarrays of size k, compute their sums and finally return maximum of all sums.
Time complexity of this solution is O(n*k)

An Efficient Solution is based on the fact that sum of a subarray (or window) of size k can be obtained in O(1) time using the sum of previous subarray
(or window) of size k. Except for the first subarray of size k, for other subarrays, we compute sum by removing the first element of the last window and
adding the last element of the current window.

Below is implementation of above 
```
int maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int curr_sum=0;
        int res=0;
        for(int i=0;i<K;i++)
        {
            curr_sum=curr_sum+Arr[i];
        }
        res=curr_sum;
        
        for(int j=K;j<N;j++)
        {
            curr_sum+=Arr[j]-Arr[j-K];
            res=max(curr_sum,res);
        }
        return res;
    }
```

### Leetcode 
You are given an integer array nums and an integer k. Find the maximum subarray sum of all 
the subarrays of nums that meet the following conditions:

The length of the subarray is k, and
All the elements of the subarray are distinct.
Return the maximum subarray sum of all the subarrays that meet the conditions. 
If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.
Example 1:

Input: nums = [1,5,4,2,9,9,9], k = 3
Output: 15
Explanation: The subarrays of nums with length 3 are:
- [1,5,4] which meets the requirements and has a sum of 10.
- [5,4,2] which meets the requirements and has a sum of 11.
- [4,2,9] which meets the requirements and has a sum of 15.
- [2,9,9] which does not meet the requirements because the element 9 is repeated.
- [9,9,9] which does not meet the requirements because the element 9 is repeated.
We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
Example 2:

Input: nums = [4,4,4], k = 3
Output: 0
Explanation: The subarrays of nums with length 3 are:
- [4,4,4] which does not meet the requirements because the element 4 is repeated.
We return 0 because no subarrays meet the conditions.
 

Constraints:

1 <= k <= nums.length <= 105
1 <= nums[i] <= 105


```
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var maximumSubarraySum = function(nums, k) {
    let i=0,j=0;
    let map= new Map();
    let sum=0;maxSum=0;
    while(i<nums.length && j< nums.length){
         
        if(j-i+1<=k){
           
           if(map.has(nums[j])){
                     i=map.get(nums[i])+1;//reset window start to the index where repitition 
                                         //occured +1
                     j=i;
                     map.clear();
                     sum=0;
                     continue;
           }
          else{
            sum=sum+nums[j];
            map.set(nums[j],j); 
                   if(j-i+1==k){
                     maxSum= sum>maxSum?sum:maxSum;
                     sum=sum-nums[i];
                     map.delete(nums[i]);
                     i=i+1;
                   }
            j++;
          }
        }
    }
    return maxSum;
};

```
