/*
ARRAYS-TARGET SUM PAIRS
Take as input N, the size of array. Take N more inputs and store that in an array. Take as input “target”, a number. Write a function which prints all pairs of numbers which sum to target.

Input Format:
The first line contains input N. Next N lines contains the elements of array and (N+1)th line contains target number.

Constraints:
Length of the arrays should be between 1 and 1000.

Output Format
Print all the pairs of numbers which sum to target. Print each pair in increasing order.

Sample Input
5
1
3
4
2
5
5
Sample Output
1 and 4
2 and 3*/
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
