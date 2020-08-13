/*
Time Complexity- O(nlogn) 
*/
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
Node* midPoint(Node* head){
    if(head==NULL || head->next==NULL)
    return head;
    Node *fast=head->next;//Important,in cas of even length ll , we need mid as left mid
    //coz imagine we have LL as 5->3 if mid is 3,a=3,b=null,left of a will not be checked for sorting
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
  
    return slow;
}
Node* merge(Node* head1,Node* head2)
{
    if(!head1)
    return head2;
    
    if(!head2)
    return head1;
    
    Node* finalHead=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data<head2->data)
        {  finalHead=head1;
           finalHead->next=merge(head1->next,head2);
            return finalHead;
        }
        else{
            finalHead=head2;
            finalHead->next=merge(head1,head2->next);
            return finalHead;
        }
    }
}
Node* mergeSort(Node *head){
   
    if(head==NULL || head->next==NULL)
      return head;
      Node *mid=midPoint(head);
      Node *a=head;
      Node *b=mid->next;
      mid->next=NULL;
      a=mergeSort(a);
      b=mergeSort(b);
      Node* c=merge(a,b);
      return c;
}
int main() {
	int n,x;
	cin>>n;
	Node *head=NULL; 

	cin>>x;
	head=new Node(x);
		Node *tail=head;
	for(int i=1;i<n;i++)
	{  
	    cin>>x;
	    tail->next=new Node(x);
	    tail=tail->next;
	}

	Node *sortedL=mergeSort(head);
	while(sortedL!=NULL)
	{
	    cout<<sortedL->data<<" ";
	    sortedL=sortedL->next;
	}
	return 0;
}
