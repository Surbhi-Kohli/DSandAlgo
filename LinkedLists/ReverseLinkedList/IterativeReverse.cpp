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

Node* reverseK(Node* head)
{  
	int count=0;
	if(head==NULL || head->next==NULL)
	return head;
	Node *current=head;
	Node *N=NULL;
	Node *prev=NULL;
	
	while(current!=NULL)
	{
      N=current->next;
	  current->next=prev;
	  prev=current;
	  current=N;
	  
	}

head=prev;
return head;
}
int main() {
	int n;
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
  
   Node* ans= reverseK(head);
   while(ans!=NULL)
   {
	   cout<<ans->data<<" ";
	   ans=ans->next;
   }
	return 0;
}
