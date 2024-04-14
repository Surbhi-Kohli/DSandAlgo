## Find the Majority Element that occurs more than N/2 times

Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. [[  You may consider that such an element always exists in the array.]] 

_Example 1_:
Input Format : N = 3, nums[] = [3,2,3] 
Result : 3  
Explanation : When we just count the occurrences of each number and compare with half of the size of the array, you will get 3 for the above solution. 

_Example 2_:
Input Format: N = 7, nums[] = [2,2,1,1,1,2,2]  
Result : 2  
Explanation : After counting the number of times each element appears and comparing it with half of array size, we get 2 as result.

_Example 3_:
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
Use a better data structure to reduce the number of look-up operations and hence the time complexity. Moreover, we have been calculating the count of the same element again 
and again - so we have to reduce that also.

#### Approach: 
     *  Use a hashmap and store as (key, value) pairs. (Can also use frequency array based on the  
        size of nums) 
     *  Here the key will be the element of the array and the value will be the number of times it 
        occurs. 
     *  Traverse the array and update the value of the key. Simultaneously check if the value is 
        greater than the floor of N/2. 
        * If yes, return the key 
        * Else iterate forward.  
        
#### Code:


#### Complexity Analysis:
Time Complexity: O(N*logN) + O(N), where N = size of the given array.
Reason: We are using a map data structure. Insertion in the map takes logN time???. And we are doing it for N elements. So, it results in the first term O(N*logN). The second O(N) is for checking which element occurs more than floor(N/2) times. If we use unordered_map instead, the first term will be O(N) for the best and average case and for the worst case, it will be O(N2).

Space Complexity: O(N) as we are using a map data structure.



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
