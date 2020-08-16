/*
Input: 1 2 4 3 5 6 -1
Output:
DLL post inserting at head :
6 5 3 4 2 1 
**DLL on inserting a new Node before a Node**
6 8 5 3 4 2 1 

DLL on Inserting a Nodde after a node 
6 8 5 99 3 4 2 1 

DLL post Appending :
6 8 5 99 3 4 2 1 100 
gonna delete various nodes 
8 5 99 3 4 2 1 100 
8 99 3 4 2 1 100 
8 3 4 2 1 100 

*/

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
    if(afterNode==NULL)
    {
        cout<<"this cant be NULL";
        return ;
    }
     Node *newNode=new Node();
     newNode->data=d;
    if((*head)==NULL)
    { 
      newNode->next=NULL;
      newNode->prev=NULL;
      (*head)=newNode;
      return;
    }
   
   
      Node* afterNext=afterNode->next;
     afterNode->next=newNode;
      newNode->next=afterNext;
      afterNext->prev=newNode;
      
}
void append(Node **head,int d)
{
    Node *newNode=new Node();
    newNode->data=d;
    newNode->next=NULL;
    if(*head==NULL)
    {
        newNode->prev=NULL;
        (*head)=newNode;
        return ;
    }
    Node* last=(*head);
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next=newNode;
    newNode->next=NULL;
    newNode->prev=last;
}
void print(Node* head)
{ 
    while(head!=NULL)
    {
     cout<<head->data<<" ";
     head=head->next;
    }
}
void deleteNode(Node **head,Node* del)
{
    if((*head)==NULL||del==NULL)
    return;
     if((*head)==del)
     {
         (*head)=del->next;
     }
      /* Change next only if node to be  
    deleted is NOT the last node */
    if (del->next != NULL)  
        del->next->prev = del->prev;  
  
    /* Change prev only if node to be  
    deleted is NOT the first node */
    if (del->prev != NULL)  
        del->prev->next = del->next;  
  
    /* Finally, free the memory occupied by del*/
    free(del);  
    return;  
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
  cout<<"DLL post inserting at head :"<<endl;
   print(head);
  
   insertBeforeANode(&head, head->next, 8); 
   cout<<endl<<"**DLL on inserting a new Node before a Node**";
   cout<<endl;
   print(head);
   cout<<endl;
   
   insertAfterNode(&head,head->next->next,99);
   cout<<endl<<"DLL on Inserting a Nodde after a node "<<endl;
   print(head);
   cout<<endl;
   append(&head,100);
   cout<<endl<<"DLL post Appending :"<<endl;
   print(head);
   cout<<endl;
    cout<<"gonna delete various nodes "<<endl;
    deleteNode(&head, head); /*delete first node*/
    print(head);
    cout<<endl;
    deleteNode(&head, head->next); 
      print(head);
      cout<<endl;
    deleteNode(&head, head->next);
      print(head);
   return 0;
}
