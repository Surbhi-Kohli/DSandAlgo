#include <iostream>
#include <stack>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
    
};
void isEvenOrOddLength(Node* head)
{
    Node *slow=head;
    if(head==NULL)
    cout<<"length of linked list is 0"<<endl;
    else if(head->next==NULL)
    {
        cout<<"length of linked list is one"<<endl;
    }
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {   
        slow=slow->next;
        fast=fast->next->next;
        
    }
    if(fast!=NULL)
    cout<<"Linked List has even length";
    else
    cout<<"Linked List has odd length";

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
 isEvenOrOddLength(head);

	return 0;
}
