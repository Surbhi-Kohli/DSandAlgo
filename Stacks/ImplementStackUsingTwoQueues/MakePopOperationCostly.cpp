/*

Method 2 (By making pop operation costly)
In push operation, the new element is always enqueued to q1. In pop() operation, if q2 is empty then all the elements except the last, are moved to q2.
Finally the last element is dequeued from q1 and returned.

1. push(s, x) operation:
 * Enqueue x to q1 (assuming size of q1 is unlimited).
2. pop(s) operation:
 * One by one dequeue everything except the last element from q1 and enqueue to q2.
 * Dequeue the last item of q1, the dequeued item is result, store it.
 * Swap the names of q1 and q2
 * Return the item stored in step 2.
 
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
    int curr_size;
    queue<int> q1,q2;
    public:
    Stack(){
        curr_size=0;
    }
    void push(int x)
    {
        q1.push(x);
        curr_size++;
    }
    void pop()
    {
        if(q1.empty())
        {
            return;
        }
        while(q1.size()!=1)
        {
            int t=q1.front();
            q1.pop();
            q2.push(t);
        }
        q1.pop();
        curr_size--;
        queue<int> q=q1;
        q1=q2;
        q2=q;
        
    }
    int top(){
         
         if(q1.empty())
         return -1;
         
         while(q1.size()!=1)
         {
             int t=q1.front();
             q1.pop();
             q2.push(t);
         }
         
         int topVal=q1.front();
         q1.pop();
         q2.push(topVal);
          queue<int> q=q1;
          q1=q2;
          q2=q;
        return topVal;
         
    }
    
    int size(){
        return curr_size;
    }
    bool isEmpty()
    {
        if(curr_size==0)
        return true;
        
        return false;
    }
};
int main() {
	// your code goes here
	int n;
	cin>>n;
    Stack s=new Stack();
    int x;
	for(int i=0;i<n;i++)
	{   cin>>x;
	    s.push(x);
	    cout<<"size of stack after pushing "<<x<<" is "<<s.size()<<endl;
	}
	Stack stCopy=s;
	cout<<"original stack is :"<<endl;
	while(!stCopy.isEmpty())
    {  cout<<"in while loop"<<endl;
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
