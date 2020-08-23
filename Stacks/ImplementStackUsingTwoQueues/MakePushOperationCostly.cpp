/*
This method makes sure that newly entered element is always at the front of ‘q1’, so that pop operation just dequeues from ‘q1’. 
‘q2’ is used to put every new element at front of ‘q1’.

1. push(s, x) operation’s step are described below:
  * Enqueue x to q2
  * One by one dequeue everything from q1 and enqueue to q2.
  * Swap the names of q1 and q2
2.  pop(s) operation’s function are described below:
   * Dequeue an item from q1 and return it.
   
   Input:
   6
   1 3 7 9 8 7
   
   Output:
original stack is :
   7
   8
   9
   7
   3
   1
  *********************************
  Current size of stack is 6
  7 is the element at the top of the stack
  8 is the element at the top of the stack after popping one element
  New size is 5
   
   
*/
#include <iostream>
#include <queue>
using namespace std;
class Stack{
    queue<int> q1,q2;
     int currSize;
    public:
   
    Stack(){
     currSize=0;   
    }
   
    void push(int x)
    {  currSize++;
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q=q1;
        q1=q2;
        q2=q;
    }
    void pop()
    { if(q1.empty())
       return;
       
        q1.pop();
        currSize--;
    }
    int top(){
        if(q1.empty())
        return -1;
        
        return q1.front();
    }
    int size(){
        return currSize;
    }
    bool isEmpty()
    {
        if(currSize==0)
        return true;
        
        return false;
    }
    
    
};

int main() {
	// your code goes here
	int n;
	cin>>n;
    Stack s;
    int x;
	for(int i=0;i<n;i++)
	{   cin>>x;
	    s.push(x);
	}
	Stack stCopy=s;
	cout<<"original stack is :"<<endl;
	while(!stCopy.isEmpty())
    {
        cout<<stCopy.top()<<endl;
        stCopy.pop();
    }
    cout<<"*********************************"<<endl;
    cout<<endl<<"Current size of stack is "<<s.size()<<endl;
    cout<<s.top()<<" is the element at the top of the stack"<<endl;
    
    s.pop();
    cout<<s.top()<<" is the element at the top of the stack after popping one element"<<endl;
    cout<<"New size is "<<s.size();
  
	return 0;
}
