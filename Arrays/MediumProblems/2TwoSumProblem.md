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
### Code in CPP

```
#include <bits/stdc++.h> 
using namespace std; 
void printPairs(int arr[], int n, int sum) 
{ 
    // Store counts of all elements in map m 
    unordered_map<int, int> m; 
  
    // Traverse through all elements 
    for (int i = 0; i < n; i++) { 
  
        // Search if a pair can be formed with 
        // arr[i]. 
        int rem = sum - arr[i]; 
        if (m.find(rem) != m.end()) { 
           
                cout << "(" << rem << ", "
                     << arr[i] << ")" << endl; 
        } 
        m[arr[i]]++; 
    } 
} 

```
Time Complexity: O(N), where N = size of the array.
Space Complexity: O(N) as we use the map data structure.
Note: We have optimized this problem enough. But if in the interview, we are not allowed to use the map data structure, then we should move on to the following approach i.e. two pointer approach. 

### Optimized Approach(using two-pointer): 

Intuition: In this approach, we will first sort the array and will try to choose the numbers in a greedy way.

We will keep a left pointer at the first index and a right pointer at the last index. Now until left < right, we will check the sum of arr[left] and arr[right]. Now if the sum < target, we need bigger numbers and so we will increment the left pointer. But if sum > target, we need to consider lesser numbers and so we will decrement the right pointer. 

If sum == target we will return either “YES” or the indices as per the question.
But if the left crosses the right pointer, we will return “NO” or {-1, -1}.

Approach:

The steps are the following:

We will sort the given array first.
Now, we will take two pointers i.e. left, which points to the first index, and right, which points to the last index.
Now using a loop we will check the sum of arr[left] and arr[right] until left < right.
If arr[left] + arr[right] > sum, we will decrement the right pointer.
If arr[left] + arr[right] < sum, we will increment the left pointer.
If arr[left] + arr[right] == sum, we will return the result.
Finally, if no results are found we will return “No” or {-1, -1}.


```

function twoSumWithSort(n, arr, target) {
    arr.sort();
    let left = 0, right = n - 1;
    while (left < right) {
        let sum = arr[left] + arr[right];
        if (sum == target) {
            return "YES";
        }
        else if (sum < target) left++;
        else right--;
    }
    return "NO";
}
let arr = [2, 6, 5, 8, 11];
console.log(twoSumWithSort(5,arr,16));//Yes
```

Time Complexity: O(N) + O(N*logN), where N = size of the array.
Reason: The loop will run at most N times. And sorting the array will take N*logN time complexity.

Space Complexity: O(1) as we are not using any extra space.

### CPP code:
/*
ARRAYS-TARGET SUM PAIRS
Take as input N, the size of array. Take N more inputs and store that in an array.
Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format:
The first line contains input N. 
Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints:
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input      Sample Output
5                   1 and 4
1                   2 and 3
3
4
2
5
5

*/
```
#include<iostream>
#include<algorithm>//to use sort function
using namespace std;

int main() {
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int target=0;
    cin>>target;
   // int l=sizeof(arr)/sizeof(int);
    sort(arr,arr+n);
   int low=0,high=n-1;
   while(low<high)
   {
       if(arr[low]+arr[high]==target)
       {
       cout<<arr[low]<<" and "<<arr[high]<<endl;
       low++;
       high--;
       }
       else if(arr[low]+arr[high]>target)
       high--;
       else
       low++;
   }
    
	return 0;
}

```
