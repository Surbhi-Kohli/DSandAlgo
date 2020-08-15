#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;
    
};

void insertAtHead(Node **head,int x)
{ 
   Node* temp=new Node();
   temp->data=x;
   temp->prev=NULL;
   
   temp->next=(*head);
   
   if((*head)!=NULL)
   (*head)->prev=temp;
   
   (*head)=temp;
   
    
}
void insertBeforeANode(Node **head,Node *pehla,int d)
{
    Node* before=NULL;
    Node* temp=(*head);
    while(temp!=pehla)
    {
        before=temp;
        temp=temp->next;
    }
      Node* newN=new Node();
      newN->data=d;
      newN->next=pehla;
      newN->prev=before;
      before->next=newN;
      pehla->prev=newN;
       if(newN->prev==NULL)
         (*head)=newN;
  
    
}
void print(Node* head)
{ 
   
    while(head!=NULL)
    {
     cout<<head->data<<" ";
     head=head->next;
        
    }
}
int main() {
  //Creating DLL;
  Node *head=NULL;
  int x;
  cin>>x;
  while(x!=-1)
  {  
      insertAtHead(&head,x);
      cin>>x;
  }
 
  print(head);
   insertBeforeANode(&head, head->next, 8); 
   cout<<endl<<"****************************";
   cout<<endl;
    print(head);
	return 0;
}
