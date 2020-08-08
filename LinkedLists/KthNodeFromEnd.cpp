/*
Given a linked list with n nodes. Find the kth element from last without computing the length of the linked list.

Input Format
First line contains space separated integers representing the node values of the linked list. The list ends when the input comes as '-1'.
The next line contains a single integer k.

Constraints
n < 10^5

Output Format
Output a single line containing the node value at the kth element from last.

Sample Input
1 2 3 4 5 6 -1
3
Sample Output
4
Explanation
The linked list is 1 2 3 4 5 6. -1 is not included in the list. So the third element from the last is 4


*/
#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
	Node(int d){
     data=d;
	}
};
void kthFromLastInLinkedList(Node *head,int k)
{
    if(head==NULL || head->next==NULL)
    return;
	Node *fast=head;
	Node *slow=head;
	int count=1;
	while(fast!=NULL && count<k)
	{
       fast = fast->next;
	   count++; 
	}
	while(fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}
	cout<<slow->data;//kth node of linked list
}
int main() {
	int x;
	cin>>x;
	Node *head=new Node(x);
	Node *temp=head;
	cin>>x;
	while(x!=-1)
	{
        temp->next=new Node(x);
		temp=temp->next;
		cin>>x;
	}

	int k;
	cin>>k;

	kthFromLastInLinkedList(head,k);

	return 0;
}0000000000
