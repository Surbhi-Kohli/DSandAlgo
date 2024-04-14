## Sort an array of 0s, 1s and 2s
Problem Statement: Given an array consisting of only 0s, 1s, and 2s. 
Write a program to in-place sort the array without using inbuilt sort functions. 
( Expected: Single pass-O(N) and constant space)

### Brute Force approach Algorithm / Intuition
Sorting ( even if it is not the expected solution here but it can be considered as one of the approaches). 
Since the array contains only 3 integers, 0, 1, and 2. 
Simply sorting the array would arrange the elements in increasing order.
### Complexity Analysis
Time Complexity: O(N*logN)
Space Complexity: O(1)

### Better Approach intuition
Keeping count of values.
Since in this case there are only 3 distinct values in the array so it's easy to maintain 
the count of all, Like the count of 0, 1, and 2. This can be followed by overwriting the 
array based on the frequency(count) of the values.

```
function sortArray(arr, n) {

    let cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (let i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }

    //Replace the places in the original array:
    for (let i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's

    for (let i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's

    for (let i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's

return arr;
}
console.log(sortArray([2,1,0,1,0,2,1],7));//[0, 0, 1, 1, 1, 2, 2]

```

Time Complexity: O(N) + O(N), where N = size of the array.
First O(N) for counting the number of 0’s, 1’s, 2’s, and second O(N) for placing them correctly in the original array.

Space Complexity: O(1) as we are not using any extra space.

### Optimal Approach:
This problem is a variation of the popular Dutch National flag algorithm. 

This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:

arr[0….low-1] contains 0. [Extreme left part]
arr[low….mid-1] contains 1.
arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
The middle part i.e. arr[mid….high] is assumed to be the unsorted segment.  

<img width="458" alt="Screenshot 2024-04-13 at 11 15 57 PM" src="https://github.com/Surbhi-Kohli/DSandAlgo/assets/32058209/8099ff19-2c82-4000-8aab-7aaeaa63f9e1">

In our case, we can assume that the entire given array is unsorted and so we will place the pointers accordingly. For example, if the given array is: [2,0,2,1,1,0], the array with the 3 pointers will look like the following:


Here, as the entire array is unsorted, we have placed the mid pointer in the first index and the high pointer in the last index. The low is also pointing to the first index as we have no other index before 0. Here, we are mostly interested in placing the ‘mid’ pointer and the ‘high’ pointer as they represent the unsorted part in the hypothetical array.

Now, let’s understand how the pointers will work to make the array sorted.

Approach:

Note: Here in this tutorial we will work based on the value of the mid pointer.

The steps will be the following:

1.First, we will run a loop that will continue until mid <= high.
2.There can be three different values of mid pointer i.e. arr[mid]
   * If arr[mid] == 0, we will swap arr[low] and arr[mid] and will increment both low and mid. Now 
     the subarray from index 0 to (low-1) only contains 0.
   * If arr[mid] == 1, we will just increment the mid pointer and then the index (mid-1) will point 
     to 1 as it should according to the rules.
   *  If arr[mid] == 2, we will swap arr[mid] and arr[high] and will decrement high. Now the  
      subarray from index high+1 to (n-1) only contains 2.
      In this step, we will do nothing to the mid-pointer as even after swapping, the subarray from 
      mid to high(after decrementing high) might be unsorted. So, we will check the value of mid 
      again in the next iteration.
3.Finally, our array should be sorted.


```
function sortArray(arr, n) {

let low=0,mid=0,high=n-1;
  while (mid <= high) {
        if (arr[mid] == 0) {
            let temp=arr[low];
            arr[low] = arr[mid];
           arr[mid]=temp;
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else {
        let temp= arr[mid];
        arr[mid] = arr[high];
        arr[high]= temp;
        high--;
        }
    }
return arr;
}
console.log(sortArray([2,1,0,1,0,2,1],7));

Time Complexity: O(N), where N = size of the given array.
Reason: We are using a single loop that can run at most N times.

Space Complexity: O(1) as we are not using any extra space.

```
