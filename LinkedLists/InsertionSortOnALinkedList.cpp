/*
Sample Input:
7
1 4 3 2 5 7 6
Sample Output:
1 2 3 4 5 6 7 

*/

#include<iostream>
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

Node* sortedInsert(Node*& head,int val)
{  
   if(head==NULL)
   {
       Node *temp=new Node(val);
       head=temp;
       return head;
   }
   else{
       if(head->data>val)
       {
           Node* temp=new Node(val);
           temp->next=head;
           head=temp;
           return head;
       }
       else
       {
           Node* temp=head;
           Node * prev=NULL;
         while(temp!=NULL && temp->data<val)
         {   prev=temp;
             temp=temp->next;
         }
         prev->next=new Node(val);
         prev=prev->next;
         prev->next=temp;
         return head;
       
      }
   }
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
   Node* sorted=NULL;
   Node* temp=head;
   while(temp!=NULL)
   { 
    sorted= sortedInsert(sorted,temp->data);
    temp=temp->next;
   }
    Node* ans=sorted;
   while(ans!=NULL)
   {
       cout<<ans->data<<" ";
       ans=ans->next;
   }
	return 0;
}
