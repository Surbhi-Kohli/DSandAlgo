/*
Mid Point runner technique-Traverse linked list using two pointers. Move one pointer by one and other pointer
by two. When the fast pointer reaches end slow pointer will reach middle of the linked list.
*/


#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
node* midPoint(node* head) //would give the right mid pt in case of even number of node in L.L
{
    if(head==NULL || head->next==NULL)
    return head;
    
    node *slow=head;
    node *fast=head;//do fast=head->next here if u want left mid pt of node in L.L
    
   while(fast!=NULL && fast->next!=NULL)
   {
       fast=fast->next->next;
       slow=slow->next;
   }
   return slow;
}

int main() {
    int n,x;
    cin>>n;
    node* head=NULL;
    
    cin>>x;
    head=new node(x);
    node* tail=head;
    node* ans=head;
    for(int i=1;i<n;i++)
    {
        cin>>x;
       tail->next=new node(x);
       tail=tail->next;
    }
  
     ans=midPoint(head);

   cout<<ans->data;//mid point of linked list
	return 0;
}
