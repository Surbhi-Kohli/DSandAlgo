/*
Finding K largest elements in a running stream at any point .We can be queried at any moment.U can assume that 
whenever we have -1 in input ,it is a query for k largest elements in stream read till now .

Running Stream-It is a stream of numbers ,u can't store all the nujmbers b'coz the data is endless

Approach to solve
1.Brute Force-We could sort the nummbers till the query and then find the k largest,but hat is not a good approach as it takes a
lot of memory to store all the numbers and sort them.Complexity-O(NlogN).

2.We can use a min heap of size k
Complexity-In worst case ,each insertion takes LogK time and also each deletion takes Log k,So overall complexity
would be O(NLogK)

Why do we use a min heap?
We use a min-heap to store k elements,so that for every new number in stream,we can compare it with min heap's top.
As min heap's top will store min element,by comparing it with current number in stream we can be sure that the current
number of stream is worth adding so that min heap stores k largest of the numbers read till now.
*/


#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

void queryPrint(priority_queue<int,vector<int>,greater<int>> pq){
    while(!pq.empty())
    {
        cout<<pq.top()<<",";
        pq.pop();
    }
    cout<<endl;
}

int main() {
   int no;
   int cs=0;//current size of heap
   int k=3;
   priority_queue<int,vector<int>,greater<int>> pq;
   while(scanf("%d",&no)!=EOF)
   {
       if(no==-1)//query time
       {
           queryPrint(pq);
       }
       else if(cs<k)  //heap size<k, so insert the number of stream to heap
       {
           pq.push(no);
           cs++;
       }
       else
       {   //size==k
           if(pq.top()<no)//if the heap's top has a number with value less than current number in stream
           {
               pq.pop();
               pq.push(no);
           }
       }
       
       
   }
	return 0;
}
