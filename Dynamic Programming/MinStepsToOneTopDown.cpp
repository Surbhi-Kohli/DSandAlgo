/*
Given a number n, count minimum steps to minimize it to 1 according to the following criteria:

* If n is divisible by 2 then we may reduce n to n/2.
* If n is divisible by 3 then you may reduce n to n/3.
* Decrement n by 1.
Examples:

Input : n = 10
Output : 3

Input : 6
Output : 2

Greedy Approach (Doesn’t work always) :
As per greedy approach we may choose the step that makes n as low as possible and continue the same, till it reaches 1.

If we observe carefully, the greedy strategy doesn’t work here.
Eg: Given n = 10 , Greedy –> 10 /2 = 5 -1 = 4 /2 = 2 /2 = 1 ( 4 steps ).
But the optimal way is –> 10 -1 = 9 /3 = 3 /3 = 1 ( 3 steps ).
So, we must think of dynamic approach for optimal solution.
Dynamic Approach:
For finding minimum steps we have three possibilities for n and they are:

f(n) = 1 + f(n-1)
f(n) = 1 + f(n/2) // if n is divisible by 2
f(n) = 1 + f(n/3) // if n is divisible by 3

*/
