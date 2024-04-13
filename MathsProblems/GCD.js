/*
Problem Statement: Find the gcd of two numbers.
Example 1:
Input:
 num1 = 4, num2 = 8
Output:
 4
Explanation:
 Since 4 is the greatest number which divides both num1 and num2.

Example 2:
Input:
 num1 = 3, num2 = 6
Output:
 3
Explanation:
 Since 3 is the greatest number which divides both num1 and num2.
Practice:
Solve Problem

*/

/*

Solution 1: Brute force

Intuition: Simply traverse from 1 to min(a,b) and check for every number.

Approach: 

Traverse from 1 to min(a,b).
And check if i is divisible by both a and b.If yes store it in the answer.
Find the maximum value of i which divides both a and b.



Another way: u can start reverse loop , but that will also not be effecient in 
case of finding gcd(11,13)

*
/
function gcd(a,b){

let gcdVal;
for(let i=Math.min(a,b);i>0;i--){
   if(a%i==0 && b%i==0){
     gcdVal=i;
     break;
}
}
return gcdVal;

}
console.log(gcd(1,8));//1
console.log(gcd(18,8));//2
console.log(gcd(10,5));//5
console.log(gcd(11,13));//1

/*
Time Complexity: O(N).
Space Complexity: O(1).
*/


/*-----------------Better Approach via Euclidean theorem----------------------------*/


/**
Intuition: Gcd is the greatest number which is divided by both a and b.If a number is divided by both a and b, it is should be divided by (a-b) and b as well.

Even improvised version (a-b) done a number of times == a/b
Approach:

Recursively call gcd(b,a%b) function till the base condition is hit.
b==0 is the base condition.When base condition is hit return a,as gcd(a,0) is equal to a.
*/

function gcdEuclidean(a,b){
while(a>0 && b>0){
if(a>b)
a=a%b;
else
b=b%a;
}
if(a==0)
return b;
else return a;
}
console.log(gcdEuclidean(1,8));
console.log(gcdEuclidean(18,8));
console.log(gcdEuclidean(10,5));
console.log(gcdEuclidean(11,13));

/*
Time Complexity: O(logɸmin(a,b)), where ɸ is 1.61.
Why log: whenever there is a division happening, the no of iterations are logarithmic.
Why phi ie ɸ why not base 10 , the divisor fluctuates in values, so depending on that value, 
so we gave a generic term.

Space Complexity: O(1).
*/
