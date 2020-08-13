/*
Input:
9
9 8 7 6 5 4 3 2 1
Output:
1 2 3 4 5 6 7 8 9 
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

void printReverse(Node* head)
{  
    if(head->next!=NULL)
    {
        printReverse(head->next);
    }
    cout<<head->data<<" ";
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
  
   printReverse(head);
   
	return 0;
}
