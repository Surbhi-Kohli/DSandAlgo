/*
Given a linked list of length N and an integer K , append the last K elements of a linked list to the front. Note that K can be greater than N.

Input Format
First line contains a single integer N denoting the size of the linked list.
Second line contains N space separated integers denoting the elements of the linked list.
Third line contains a single integer K denoting the number of elements that are to be appended.

Constraints
1 <= N <= 10^4
1 <= K <= 10^4

Output Format
Display all the elements in the modified linked list.

Sample Input
7
1 2 2 1 8 5 6
3
Sample Output
8 5 6 1 2 2 1
Explanation
Initially the linked list is
1→ 2→ 3 → 4 → 5 → 6→ null
and k = 2. After appending the last two elements to the front , the new linked list looks like
5→ 6→ 1→ 2→ 3 → 4 → null
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
node* append(node*& head,int k)
{
  int jumps=1,l2=0;
  node* slow=head;
  node* fast=head;
  while(jumps<k)
  { 
   fast=fast->next;
    jumps++;
  }
  node *prev=NULL;
  //node* temp=current;
  //head=current;
  while(fast->next!=NULL)
  {  prev=slow;
     fast=fast->next;
     slow=slow->next;
  }
 
  prev->next=NULL;
 fast->next=head;
 head=slow;
  
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
    cin>>k;
    if(k<n)
    {
          ans=append(head,k);
    }
    
else if(k>n) //important
{
    k=k-n;
    ans=append(head,k);
}
   while(ans!=NULL)
   {
    cout<<ans->data<<" ";
    ans=ans->next;
   }
	return 0;
}
