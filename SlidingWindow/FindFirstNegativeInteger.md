## First negative integer in every window of size k
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

Example 1:

Input : 
N = 5
A[] = {-8, 2, 3, -6, 10}
K = 2
Output : 
-8 0 -6 -6
Explanation :
First negative integer for each window of size k
{-8, 2} = -8
{2, 3} = 0 (does not contain a negative integer)
{3, -6} = -6
{-6, 10} = -6
 
Example 2:
Input : 
N = 8
A[] = {12, -1, -7, 8, -15, 30, 16, 28}
K = 3
Output :
-1 -1 -7 -15 -15 0 

Example 3:
8
12 -1 -7 8 -15 30 16 28
3
Output: -1 -1 -7 -15 -15 0

```
class Solution {
/**
* @param number n
* @param number k
* @param number[] arr

* @returns number[]
*/
    printFirstNegativeInteger(n, k, arr) {
        // code here
        let i=0,j=0;
        let temp=[];
        let ans=[];
        
        while(i<n && j<n){
            if(j-i+1<k){
                if(arr[j]<0){
                    temp.push(arr[j]);
                  
                }
                  
            }
            else{
                
              if(j-i+1==k){
                   if(arr[j]<0){
                    temp.push(arr[j]);
                  
                   }
                if(temp.length==0){
                    ans.push(0)
                }
                else{
                    ans.push(temp[0]);
                    if(temp[0]==arr[i])//if we used the value at arr[i] ie it was -ve ,
//so we will now remove that from our temp array
                    temp.shift();
                }
             
                i++;
            }
        }
          j++;
           
        }
        return ans;
    }
}
        


```
