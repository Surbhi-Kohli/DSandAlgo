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
node* recReverse(node* head)
{
    if(head==NULL || head->next==NULL)
    return head;
    
    node *smallHead=recReverse(head->next);
    
    node *C=head;
    C->next->next=C;
    C->next=NULL;
    return smallHead;
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
  
          ans=recReverse(head);

   while(ans!=NULL)
   {
    cout<<ans->data<<" ";
    ans=ans->next;
   }
	return 0;
}
