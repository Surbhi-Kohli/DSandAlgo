/*
Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5
Sample Output
1 4 9 3 8 7 5 6 2
Explanation
N = 9 & K = 3

Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5

After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2


*/
#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node *next;
	Node(int d){
      data=d;
	  next=NULL;
	}
};

Node* reverseK(Node* head,int k)
{  
	int count=0;
	if(head==NULL || head->next==NULL)
	return head;
	Node *current=head;
	Node *N=NULL;
	Node *prev=NULL;
	
	while(count!=k && current!=NULL)
	{
      N=current->next;
	  current->next=prev;
	  prev=current;
	  current=N;
	  count++;
	}

	if(N!=NULL)
	head->next=reverseK(N,k);

	return prev;
}
int main() {
	int n,k;
	cin>>n;


	cin>>k; 

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
  
   Node* ans= reverseK(head,k);
   while(ans!=NULL)
   {
	   cout<<ans->data<<" ";
	   ans=ans->next;
   }
	return 0;
}
