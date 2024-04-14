## Find the Majority Element that occurs more than N/2 times

Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. [[  You may consider that such an element always exists in the array.]] 

Example 1:
Input Format : N = 3, nums[] = [3,2,3] 
Result : 3  
Explanation : When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution. 

Example 2:
Input Format: N = 7, nums[] = [2,2,1,1,1,2,2]  
Result : 2  
Explanation : After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

Example 3:
Input Format:  N = 10, nums[] = [4,4,2,4,3,4,4,3,2,4] 
Result : 4

### Brute Force Approach:
The steps are as follows:

  * We will run a loop that will select the elements of the array one by one.
  * Now, for each element, we will run another loop and count its occurrence in the given array.
  * If any element occurs more than the floor of (N/2), we will simply return it.

#### Complexity Analysis:
Time Complexity: O(N2), where N = size of the given array. Reason: For every element of the array the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N2). Space Complexity: O(1) as we use no extra space.

### Better Approach: Use of a map


### Most Optimized approach: Moore's Voting algorithm

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let el,cnt;
    cnt=0;
    for(let i=0;i<nums.length;i++){
  
    if(cnt==0)
    {
        el=nums[i];
        cnt=1;
    }
    else if(nums[i]==el)
    cnt++
    else cnt--;
    }
    if(cnt==0)
    return -1;


//If problem states that there always exists a majority element ,
// you can skip the following code
// and simply return el
    let count=0;
    for(let i =0;i<nums.length;i++){
    if(nums[i]==el){
        count++
    }
    }
 
    if(count>nums.length/2)
    return el;
    else return -1;
};

```
