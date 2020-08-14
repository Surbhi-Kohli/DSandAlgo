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

Time Complexity: O(n)
Auxiliary Space: O(n) if Function Call Stack size is considered, otherwise O(1).
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

bool isPalindromeUtil(Node *&left,Node *right)//It is important to pass left pointer as ref..
{   //Reason:Passing single pointer is as good as pass by value & so then we pass same pptr again n again.
        //We need to pass the address for reflecting the canges in parent recursive calls//V.Important
    
    if(right==NULL)
    {
        return true;
    }
    bool isp=isPalindromeUtil(left,right->next);
    
    if(isp==false)
    return false;
    
    bool isp1=(right->data==left->data);
    left=left->next;// we want this updated value for left in parent call ,so *& was used in params
    return isp1;
    
}

bool isPalindrome(Node* head)
{
    return isPalindromeUtil(head,head);
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
 {
     cout<<"true"<<endl;
 }
 else{
     cout<<"false"<<endl;
 }
	return 0;
}
