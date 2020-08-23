#include <iostream>
#include <stack>
using namespace std;


void transfer(stack<int> &st,stack<int> &s2,int n)
{
    for(int i=0;i<n;i++)
    {
        s2.push(st.top());
        st.pop();
    }
}

void  reverseStack(stack<int> &st)
{
   stack<int> s2;
   int n=st.size();
   for(int i=0;i<n;i++){
       int x=st.top();
       st.pop();
       transfer(st,s2,n-i-1);
       st.push(x);
       transfer(s2,st,n-i-1);
       
   }
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
    reverseStack(st);
	while(st.empty()==false)
	{
	    cout<<st.top()<<" ";
	    st.pop();
	}
	return 0;
}
