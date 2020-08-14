/*
Check if a linked list is a palindrome.( Boolean return type )

Input Format
Add N space separated elements in the list

Constraints
None

Output Format
Boolean answer( true or false)

Sample Input
5
1 2 3 6 8
Sample Output
false

Time Complexity-O(n)
Space Complexity-O(n)
*/
#include <iostream>
#include <stack>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node(int d){
      data=d;
	  next=NULL;
	}
};

bool isPalindrome(Node* head)
{
    stack<int> st;
    Node *temp=head;
    while(temp!=NULL)
    {
        st.push(temp->data);
        temp=temp->next;   
    }
    temp=head;
    while(temp!=NULL && !st.empty())
    {
        if(st.top()!=temp->data)
        {
             return false;
        }
       
        st.pop();
        temp=temp->next;
    }
    return true; 
}
int main() {
	int n,val;
	cin>>n;
	int x;
	Node *head=NULL;
    
    cin>>x;
    head=new Node(x);
    Node *tail=head;
   for(int i=1;i<n;i++)
   {   cin>>x;
      
	   tail->next=new Node(x);
	   tail=tail->next;
	 
   }
 bool ans=isPalindrome(head);

 if(ans)
 cout<<"true"<<endl;
 else
 cout<<"false"<<endl;
	return 0;
}
