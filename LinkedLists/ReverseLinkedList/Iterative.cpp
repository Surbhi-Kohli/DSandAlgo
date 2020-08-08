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
node* reverse(node*& head)
{
    
 node *prev=head;
 node *temp;
 node *nNode;
 if(head==NULL || head->next==NULL)
 return head;
 temp=head->next;
 
  if(temp->next!=NULL)
  nNode=temp->next;
  node *prePrev=NULL;
  while(temp!=NULL)
  {   if(prev==head)
      prev->next=NULL;
     
      temp->next=prev;
      if(nNode==NULL)
      {
          break;
      }
      prev=temp;
      temp=nNode;
      nNode=temp->next;
  }

  head=temp;
  return head;
}
int main() {
    int n,x,k;
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
  
          ans=reverse(head);

   while(ans!=NULL)
   {
    cout<<ans->data<<" ";
    ans=ans->next;
   }
	return 0;
}
