/*
Given an expression string exp, write a program to examine whether the pairs and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.


Time Complexity: O(n)
Auxiliary Space: O(n) for stack for the below solution.
Input:[()]{}{[()()]()}
Output:The expression is balanced
Input:[(])
Output:The expression is not balanced
*/

#include <iostream>
#include <stack>
using namespace std;

bool checkForBalancedParenthesis(string s)
{
    int n=s.length();
    stack<char> st;
    char ch;
    for(int i=0;i<n;i++)
    {
      if(s[i]=='(' || s[i]=='{' || s[i]=='[')
      {
          st.push(s[i]);
          continue;
      }
       if(st.empty())
       {
         return false;
       }
       switch(s[i])
       {
           case ')':
            ch=st.top();
           st.pop();
           if(ch=='{'|| ch=='[')
            return false;
           break;
           case '}':
            ch=st.top();
           st.pop();
           if(ch=='(' || ch=='[')
           return false;
           break;
           case ']':
            ch=st.top();
           st.pop();
           if(ch=='(' || ch=='{')
           return false;
           break;
           
       }
     
    }
    return st.empty();
}

int main() {

string s;
cin>>s;
 bool ans=checkForBalancedParenthesis(s);
  if(ans)
  {
      cout<<"The expression is balanced"<<endl;
  }
  else{
      cout<<"The expression is not balanced"<<endl;
  }
	return 0;
}
