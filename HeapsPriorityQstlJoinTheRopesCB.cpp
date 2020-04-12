/*
Join the ropes-Given N ropes of different sizes,we are supposed to join the ropes together.The cost of joining 2
ropes of different size 'a' and 'b' is a+b.Find the minimum cost inorder to join all ropes to make one rope.

Explanation:Consider 4 ropes R4,R3,R2,R6 of sizes 4,3,2,6 respectively.
Consider the following ways of joining these ropes.

Way 1.
Step 1.Join R4 n R6.
cost=0+10, Final ropes= R10,R2,R3

Step 2. Join R10 n R3
cost=0+10+13,final Ropes=R13,R2

Step 3.Join R13 n R2
cost=0+10+13+15=38=final cost ,Rope=R38

Way 2
Step 1.Join R2 n R3
cost=0+5,Final ropes=R5,R6,R4

Step 2.Join R5 n R4
cost=0+5+9,Final ropes=R9, R6

Step 3.Join R9 n R6
cost=0+5+9+15=29,Rope=R29

Comparing the above 2 ways it is evident that if in initail stage ,we add larger cost ropes,those larger
value get repeated in addition again and again to the cost making the overall cost go up drastically.
Whereas ,if we begin by adding smaller cost ropes in initial stage,those smaller values get repeated in 
overall cost n thus final cost remains minimized.

Method to Solve
Brute Force:
Exhaust all possible ways of joining and get minimum cost out of all the ways. Time Complexity-Exponential

Using Heaps-We push all the cost values of the ropes on a min heap.Extract the 2 min values and push the cost back in 
heap signifying the newly formed rope.Heap is the best choice to find least elements out of given elements.
We get min element in O(1)
So we proceed as follows
1.Pop out the smallest rope.
2.Pop the second smallest rope.
Add or join the ropes and put them back in heap

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int connectTheRopeWithMinCost(int *ropes,int n)
{
    priority_queue<int,vector<int>,greater<int>>pq (ropes,ropes+n);//passing the ropes array n its size
    int cost=0;
    while(pq.size()>1)//coz we need to extract 2 elements,So size must be greater than 1
    { 
        int first=pq.top();
        pq.pop();

        int second=pq.top();
        pq.pop();
        
        cost+=(first+second);
        pq.push(first+second);
    }
    return cost;
}
int main() {

	int n;
	cin>>n;//4
		int  *arr=new int[n];
	for(int i=0;i<n;i++)
	{
	    int x;
	    cin>>x;  //4 3 2 6
	    arr[i]=x;
	}
	cout<<connectTheRopeWithMinCost(arr,n);//29
	return 0;
}
