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

This method takes O(n) time and O(1) extra space

*/

#include <iostream>
#include <stack>
using namespace std;
bool isEvenLength=false;
class Node{
	public:
	int data;
	Node *next;
	Node(int d){
      data=d;
	  next=NULL;
	}
};
Node* findMid(Node *head)
{
    Node *slow=head;
    if(head==NULL || head->next==NULL)
    return head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {   
        slow=slow->next;
        fast=fast->next->next;
        
      //  cout<<"Slow is "<<slow->data<<endl;
    //   cout<<"fast is "<<fast->data<<endl;
    }
    if(fast!=NULL)
    isEvenLength=true;
    //cout<<"out of while"<<endl;
    //cout<<"slow - mid is "<<slow->data<<endl;
    return slow;
    
}
bool isPalindrome(Node *head)
{
   Node* mid=findMid(head);
   //cout<<"mid is "<<mid->data<<endl;
   Node *newH=NULL;
  
   
   if(mid->next!=NULL)
     newH=mid->next;
     Node *temp=newH;
     Node *prev=NULL;
     Node*  N=NULL;
     while(temp!=NULL)
     {
         N=temp->next;
         temp->next=prev;
         prev=temp;
         temp=N;
     }
     newH=prev;
     
     if(isEvenLength==false)
     {
          while(newH!=NULL && head!=mid)// we dont hv to include mid element
        {
         if(newH->data!=head->data)
         return false;
         newH=newH->next;
         head=head->next;
       }
     }
     else{
         while(newH!=NULL)
         {
              if(newH->data!=head->data)
               return false;
         newH=newH->next;
         head=head->next;
         }
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
 if(ans==0)
 {
     cout<<"false"<<endl;
 }
 else{
     cout<<"true"<<endl;
 }
	return 0;
}
