## Stock Buy And Sell
Problem Statement: You are given an array of prices where prices[i] is the 
price of a given stock on an ith day.

You want to maximize your profit by choosing a single day to buy one stock 
and choosing a different day in the future to sell that stock. 
Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0.

#### Examples
##### Example 1:
Input:
 prices = [7,1,5,3,6,4]
Output:
 5
Explanation:
 Buy on day 2 (price = 1) and 
sell on day 5 (price = 6), profit = 6-1 = 5.

Note
: That buying on day 2 and selling on day 1 
is not allowed because you must buy before 
you sell.

##### Example 2:
Input:
 prices = [7,6,4,3,1]
Output:
 0
Explanation:
 In this case, no transactions are 
done and the max profit = 0.

#### Brute Force Approach
Algorithm / Intuition
Intuition: We can simply use 2 loops and track every transaction and 
maintain a variable maxPro to contain the max value among all transactions.

Approach: 

Use a for loop of ‘i’ from 0 to n.
Use another for loop of j from ‘i+1’ to n.
If arr[j] > arr[i] , take the difference and compare  and store it in the maxPro variable.
Return maxPro.

#### Complexity Analysis
Time complexity: O(n^2)
Space Complexity: O(1)

#### Better Approach:
Intuition: We will linearly travel the array. We can maintain a minimum from the start
of the array and compare it with every element of the array, if it is greater than the minimum then
take the difference and maintain it in maxProfit, otherwise update the minimum.

#### Approach:

* Create a variable maxProfit and store 0 initially.
* Create a variable minPrice and store some larger value(ex: MAX_VALUE) value initially.
* Run a for loop from 0 to n.
* Update the minPrice if it is greater than the current element of the array
* Take the difference of the minPrice with the current element of the array and
  compare and maintain it in maxPro.
* Return the maxPro.

  ```
function maxProfit(arr) {
    let maxProfit = 0;
    let n = arr.length;
    let minPrice = Infinity;

    for (let i = 0; i < arr.length; i++) {
        minPrice = minPrice<arr[i]?minPrice:arr[i];
        maxProfit = maxProfit>arr[i] - minPrice?maxProfit:arr[i] - minPrice;
    }
    
    return maxProfit;
 }

    let arr = [7,1,5,3,6,4];
    let maxPro = maxProfit(arr);
    console.log("Max profit is: ",maxPro);

  ```
 
#### Complexity Analysis
Time complexity: O(n)

Space Complexity: O(1)
