#include <iostream>
#include <queue>
using namespace std;

int main() {
	// your code goes here
	priority_queue<int> pq; //Min heap or Max Heap?????->will be a max-heap by default
	int a[]={5,6,17,18,9,11};
	//Insert this in q
	for(int i=0;i<6;i++)
	pq.push(a[i]);
	
	while(!pq.empty())
	{
	    cout<<pq.top()<<", ";   //18, 17, 11, 9, 6, 5, 
	    pq.pop();
	}
	cout<<endl;
	priority_queue<int,vector<int>,greater<int>> minQ; //Using this syntax to make it min_heap
	
		for(int i=0;i<6;i++)
         minQ.push(a[i]);
         
    while(!minQ.empty())
	{
	    cout<<minQ.top()<<", ";   //5, 6, 9, 11, 17, 18, 
	    minQ.pop();
	}     
	
	return 0;
}
