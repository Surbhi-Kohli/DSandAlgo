/*
ARRAYS-TARGET SUM TRIPLETS
Take as input N, the size of array. Take N more inputs and store that in an array.
Take as input “target”, a number. 
Write a function which prints all triplets of numbers which sum to target.
Input Format:First line contains input N. Next N lines contains the elements of array and N+1 line contains target number.
Constraints:
Length of Array should be between 1 and 1000.
Output Format
Print all the triplet present in  the array.
Sample Input
9
5
7
9
1
2
4
6
8
3
10
Sample Output
1, 2 and 7
1, 3 and 6
1, 4 and 5
2, 3 and 5
O(n^2)
*/
// function to print triplets with given sum 
void findTriplets(int arr[], int n, int sum) 
{ 
    for (int i = 0; i < n - 1; i++) { 
        // Find all pairs with sum equals to 
        // "sum-arr[i]" 
        unordered_set<int> s; 
        for (int j = i + 1; j < n; j++) { 
            int x = sum - (arr[i] + arr[j]); 
            if (s.find(x) != s.end()) 
                printf("%d %d %d\n", x, arr[i], arr[j]); 
            else
                s.insert(arr[j]); 
        } 
    } 
} 
  
