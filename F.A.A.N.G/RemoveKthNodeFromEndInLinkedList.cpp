/*
Given a linked list, remove the k-th node from the end of list.

Input Format
First line contains a single integer N denoting the size of the linked list.
Second line contains a single integer K denoting remove k-th node from the end of list
Third line contains N space separated integers denoting the elements of the linked list.

Constraints
Note :Given k will always be valid.

Output Format
Display updated linked list

Sample Input
15 
3
1 2 2 1 2 3 4 5 6 1 2 3 4 5 7
Sample Output
1 2 2 1 2 3 4 5 6 1 2 3 5 7

*/
#include<iostream>
using namespace std;
class Node
{    public:
	int data;
	Node *next;
	Node(int d){
		next=NULL;
		data=d;
	}

};
void kthNodeFromEnd(Node *head,int k){
	if(head==NULL)
	return;
  Node *f=head;
  Node *s=head;
  Node *prev=NULL;
  int count=1;
   while(count!=k)
   {
	   f=f->next;
	   count++;
   }

   	while(f->next!=NULL)
	{
	    prev=s;
		s=s->next;
		f=f->next;
	}
    prev->next=s->next;
	delete s;

    Node *t=head;
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}

	int main() {
	int n;
	cin>>n;
	int k;
	cin>>k;
	int x;
	cin>>x;
	Node *head=new Node(x);
	Node *temp=head;
	for(int i=1;i<n;i++)
	{
		cin>>x;
		temp->next=new Node(x);
		temp=temp->next;
	}

	kthNodeFromEnd(head,k);

	return 0;
}
