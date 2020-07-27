/*
Efficient Approach: The brute force solution is calculating the sum of each and every sub-array and checking whether the sum is zero or not.
Let’s now try to improve the time complexity by taking an extra space of ‘n’ length. The new array will store the sum of all the elements up
to that index. The sum-index pair will be stored in a hash-map. A Hash map allows insertion and deletion of key-value pair in constant time.
Therefore, the time complexity remains unaffected. So, if the same value appears twice in the array, it will be guaranteed that the 
particular array will be a zero-sum sub-array.

Algorithm:
* Create a extra space, an array of length n (prefix), a variable (sum) , length (max_len) and a hash map (hm) to store sum-index pair as a key-value pair
* Move along the input array from starting to the end
* For every index update the value of sum = sum + array[i]
* Check for every index, if the current sum is present in the hash map or not
* If present update the value of max_len to maximum of difference of two indices (current index and index in the hash-map) and max_len
* Else Put the value (sum) in the hash map, with the index as a key-value pair.
* Print the maximum length (max_len)


Complexity Analysis:
Time Complexity: O(n), as use of good hashing function will allow insertion and retrieval operations in O(1) time.
Space Complexity: O(n), for the use of extra space to store the prefix array and hashmap.

*/

#include <iostream>
#include <unordered_map>
using namespace std;
int checkSubarrayWithSumZero(int arr[],int n)
{
    unordered_map<int,int> prefixSum;
    int sum=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        if(arr[i]==0 && len==0)
        len=1;
        if(sum==0)//if sum is zero that means len of subarray with sum zero=i+1 or prev len(whichever is greater)
        len=max(i+1,len);
        if(prefixSum.find(sum)!=prefixSum.end())//If a sum repeats(non-zero sum)
        len=max(len,i-prefixSum[sum]);
       else{
           prefixSum[sum]=i;
       } 
    }
    return len;   
}
int main() {
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
    cin>>arr[i];
}
cout<<checkSubarrayWithSumZero(arr,n);
	return 0;
}
