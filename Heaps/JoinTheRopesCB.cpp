/*
Given N ropes of different sizes,we are supposed to join the ropes together.The cost of joining 2 ropes
together of different sizes 'a' and 'b' is a+b.Find the minimum cost inorder to join all ropes to make one rope.

Sol:We are supposed the to find the minimum cost of joining.
1.Brute Force Approach: Consider all possible joining scenarios and compare all costs to get min cost.
                     Complexity of such an approach-Exponential

2.Using Min Heaps:For heaps,while building heaps out of arrays ,we perform very less operations for large 
no of elements(using downheapify method) to optimize the complexity.
Consider initially we have ropes - 4,5,6,7 
Initially if we join 6+7,cost=0+6+7,
Now new ropes=4,5,6+7
If we join 5 and 6+7, cost=(0+6+7)+(6+7+5)..thus we see that factor of 6+7 repeats,
Now new ropes=4,5+6+7,we join and get final cost=(0+6+7)+(5+6+7)+(4+5+6+7)=53.In this approach we end up getting max cost
coz we started with larger valued ropes,whose cost keppt re-occuring.So we need to pick top 2 min value ropes
out of the available ropes.
So we do as follows
With ropes=4,5,6,7
We join 4+5,cost=(0+4+5),New ropes=(4+5),6,7
Now we join rope with value(4+5) and rope with value 6,new cost=(0+4+5)+(4+5+6)
New Ropes=(4+5+6),7
we join the remaining ropes n final cost=(0+4+5)+(4+5+6)+(4+5+6+7)=37

Implement Min heap,and in every iteration ,pick out the 2 smallest length ropes ,combine them,include ther cost n
re-enter the newly created rope in heap till we get a single rope
*/

#include<iostream>
#include<queue>
using namespace std;
int connectTheRopesWithMinCost(int *ropes,int n)
{
   priority_queue<int,vector<int>,greater<int>> pq(ropes,ropes+n);
   int cost=0;
    while(pq.size()>1)
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
int main(){

 int n;
 cin>>n;
 int *arr=new int[n]();
 for(int i=0;i<n;i++)
 {
  cin>>arr[i];
 }
 cout<<connectTheRopesWithMinCost(arr,n);
 return 0;
}
