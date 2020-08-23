/* Reverse a Stack using Recursion. Do not use any extra stack.

Input Format
First line contains an integer N (size of the stack).
Next N lines follow each containing an integer to be stored in the stack where the last integer is at the top of the stack.

Constraints
1 <= N <= 10^4

Output Format
Output the values of the reversed stack .

Input:
6
1 3 7 9 8 7

Output:
original stack is :
7 8 9 7 3 1 
reversed stack is :
1 3 7 9 8 7 
*/
#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st,int x)
{
    if(st.empty())
    {
        st.push(x);
        return ;
    }
    int y=st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(y);
}

void  reverseStackRecursive(stack<int> &st)
{
    if(st.empty())
    return;
    
    int x=st.top();
    st.pop();
    reverseStackRecursive(st);
    insertAtBottom(st,x);
}
int main() {
	// your code goes here
	int n;
	cin>>n;
    stack<int> st;
    int x;
	for(int i=0;i<n;i++)
	{   cin>>x;
	    st.push(x);
	}
	stack<int> stCopy=st;
	cout<<"original stack is :"<<endl;
	while(stCopy.empty()==false)
    {
        cout<<stCopy.top()<<" ";
        stCopy.pop();
    }
    cout<<endl;
    cout<<"reversed stack :"<<endl;
    reverseStackRecursive(st);
	while(st.empty()==false)
	{
	    cout<<st.top()<<" ";
	    st.pop();
	}
	return 0;
}
