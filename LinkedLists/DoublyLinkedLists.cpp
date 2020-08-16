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
void insertBeforeANode(Node **head,Node *beforeNode,int d)
{
    Node* newN=new Node();
    newN->data=d;
    Node* prevNode=beforeNode->prev;
    prevNode->next=newN;
    newN->next=beforeNode;
    beforeNode->prev=newN;
}
void insertAfterNode(Node **head,Node *afterNode,int d)
{
    Node *newNode=new Node();
    newNode->data=d;
    Node* afterNext=afterNode->next;
     afterNode->next=newNode;
      newNode->next=afterNext;
      afterNext->prev=newNode;
      
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
   cout<<endl;
   insertAfterNode(&head,head->next->next,99);
   print(head);
   return 0;
}
