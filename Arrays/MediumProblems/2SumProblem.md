## Two Sum : Check if a pair with given sum exists in Array   

Problem Statement: Given an array of integers arr[] and an integer target.


1st variant: Return YES if there exist two numbers such that their sum is equal to the target. Otherwise, return NO.

2nd variant: Return indices of the two numbers such that their sum is equal to the target. 
Otherwise, we will return {-1, -1}.

Note: You are not allowed to use the same element twice. Example: If the target is equal to 6 and num[1] = 3, then nums[1] + nums[1] = target is not a solution.

Example 1:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 14
Result: YES (for 1st variant)
       [1, 3] (for 2nd variant)
Explanation: arr[1] + arr[3] = 14. So, the answer is “YES” for the first variant and [1, 3] for 2nd variant.

Example 2:
Input Format: N = 5, arr[] = {2,6,5,8,11}, target = 15
Result: NO (for 1st variant)
	[-1, -1] (for 2nd variant)
_Explanation_: There exist no such two numbers whose sum is equal to the target.


1.Naive Approach(Brute-force approach): 
Intuition: For each element of the given array, we will try to search for another element such that its sum is equal to the target. If such two numbers exist, we will return the indices or “YES” accordingly.

```
function twoSum(n, arr, target) {
   let ans = [];
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                ans.push(i);
                ans.push(j);
                return ans;
            }
        }
    }
    return { -1, -1};
}
```

Time Complexity: O(N2), where N = size of the array.
Reason: There are two loops(i.e. nested) each running for approximately N times.

Space Complexity: O(1) as we are not using any extra space.



## Better Approach(using Hashing): 

Intuition: Basically, in the previous approach we selected one element and then searched for the other one using a loop. Here instead of using a loop, we will use the HashMap to check if the other element i.e. target-(selected element) exists. Thus we can trim down the time complexity of the problem.

And for the second variant, we will store the element along will its index in the HashMap. Thus we can easily retrieve the index of the other element i.e. target-(selected element) without iterating the array.

### Approach:

The steps are as follows:

   *  We will select the element of the array one by one using a loop(say i).
   *  Then we will check if the other required element(i.e. target-arr[i]) exists in the hashMap.
 
      * If that element exists, then we will return “YES” for the first variant or we will return 
        the current index i.e. i, and the index of the element found using map i.e.
         mp[target-arr[i]].
      * If that element does not exist, then we will just store the current element in the hashMap 
        along with its index. Because in the future, the current element might be
        a part of our answer.
   *  Finally, if we are out of the loop, that means there is no such pair whose sum is equal to the 
     target. In this case, we will return either “NO” or {-1, -1} as per the variant of the question.

```

const twoSum = (array, goal) => {
  let numberMap = new Map();

  for (let index = 0; index < array.length; index++) {
    el = array[index];

    if (numberMap.has(goal - el)) 
      return [index, numberMap.get(goal - el)];
    else numberMap.set(el, index);
  }

  return [];
}
let arr = [2, 6, 5, 8, 11];
console.log(twoSum(arr,16));
```
