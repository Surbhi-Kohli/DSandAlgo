/*
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. Note that 1 is
typically treated as an ugly number.
Example: 10th ugly number is 12, because first 10 ugly numbers are 1, 2, 3, 4, 5, 6, 8, 9, 10, 12.
One of the Approach to solve the problem:
If we carefully observe the example, We can see that an ugly number is a multiple of either 2, 3 or 5. 
Only exception is that 1 is also ugly.

Question: Starting from 1 can we multiply 1 by 2, 3, and 5 then can we get next 3 ugly numbers {2, 3, 5}?
Answer: No, because there is one more ugly number 4 before 5. So how we proceed is ,each time we pick minimum ugly
number from the current set and compute all the numbers multiples of 2,3, and 5 of that number .we then  add them to a
data structure. Next time we pick the minimum and so on.
Question: Which data structures fit where we always get min in O(1) time?
Answer: MinHeap
Solution is as follows:
we will keep a min heap and initially insert 1 as the first ugly number. The heap is {1}.
Now, for next ugly number we extract min 1 from heap and inserts the multiples of 2, 3, and 5.Now 1 was our first ugly number.
Now, the heap becomes {2, 3, 5}. For next ugly number, we extract min from heap which is 2,which becomes our 2nd ugly number. 
SO, Now, we insert 2*2=4, 2*3=6, 2*5=10 into the heap and the heap becomes {3, 4, 5, 6, 10}.
Next we extract 3 and push 3*2=6, 3*3=9, and 3*5=15. Note that, we already inserted 6 so we should not push another 6 into heap.
This operation costs us extra though n thus kind of makes this implementation inefficient as we have scope of 
recalculating already computed values.
Now heap becomes {4, 5, 6, 9, 10, 15}. And so on.
Question: What is the time and space complexity?
Answer: We extract one element at each step until we extract nth element to get the nth ugly. Each extract operation we need to do a heapify operation to maintain heap property which take O(logn) on average. So, total complexity is O(nlogn).


*/
#include <iostream>
#include <queue>
using namespace std;
int searchInHeap(priority_queue<int,vector<int>,greater<int>> pq,int n)
{
    priority_queue<int,vector<int>,greater<int>> duplicate=pq;
    while(!duplicate.empty())
    {
        if(duplicate.top()==n)
        {
            return 1;
        }
        duplicate.pop();
    }
    return 0;
}
int findNthUgly(int n)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    int count=0;
    int currUgly;
    while(!pq.empty() && count<n)
    {   
        currUgly=pq.top();
        cout<<"current Ugly Number is "<<currUgly<<endl;
        count++;
        pq.pop();
       int op1=currUgly*2;
      int op2=currUgly*3;
       int op3=currUgly*5;
      if(searchInHeap(pq,op1)==0)
       pq.push(op1);
      if(searchInHeap(pq,op2)==0)
        pq.push(op2);
        
      if(searchInHeap(pq,op3)==0);
         pq.push(op3);
      
       
        
    }
    return currUgly;
}
int main() {
	int n;
	cin>>n;
	cout<<findNthUgly(n);
	return 0;
}
