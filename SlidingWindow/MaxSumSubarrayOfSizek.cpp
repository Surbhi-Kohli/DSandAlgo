/*Find maximum (or minimum) sum of a subarray of size k

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

Below is implementation of above */
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
