/*
Given 2 sorted linked lists , merge the two given sorted linked list and print the final Linked List.

Input Format
First Line contains T the number of test cases.
For each test case :
Line 1 : N1 the size of list 1
Line 2 : N1 elements for list 1
Line 3 : N2 the size of list 2
Line 4 : N2 elements for list 2

Constraints
1 <= T <= 1000
0<= N1, N2 <= 10^6
-10^7 <= Ai <= 10^7

Output Format
For each testcase , print the node data of merged linked list.

Sample Input
1
4
1 3 5 7
3
2 4 6
Sample Output
1 2 3 4 5 6 7 
Explanation
The two lists after merging give the sorted output as [1,2,3,4,5,6,7] .

Sample Input
4
2
1 1
2
1 1
3
1 2 3
3
4 5 6
4
1 2 3 4
0
2
1 1
2
-1 2
Sample Output
1 1 1 1 
1 2 3 4 5 6 
1 2 3 4 
-1 1 1 2 


*/


#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
       data=d;
       next=NULL;
    }
};
node* merge(node *a,node *b)
{
    if(a==NULL)
    return b;
    
    if(b==NULL)
    return a;
    
    //take a head pointer
    node *c;
    if(a->data<b->data)
    {
        c=a;
        c->next=merge(a->next,b);
    }
    else{
        c=b;
        c->next=merge(a,b->next);
        
    }
    return c;
}
int main() {
	int t;
	cin>>t;
	int n,m;
	while(t--)
	{
      cin>>n;
	
	node *head1;
	node *temp;
	int x;
	if(n>0)
	{	cin>>x;
	head1=new node(x);
	 temp=head1;
	}
 else head1=NULL;
	for(int i=1;i<n;i++)
	{
	    cin>>x;
	    temp->next=new node(x);
	    temp=temp->next;
	}
	cin>>m;
	node *head2;
		node* temp2;
	if(m>0)
	{
	    cin>>x;
	   head2=new node(x);
    temp2=head2;
	}
	else head2=NULL;
	for(int i=1;i<m;i++)
	{
	    cin>>x;
	    temp2->next=new node(x);
	    temp2=temp2->next;
	}
	node *ans=merge(head1,head2);
	while(ans!=NULL)
	{
	    cout<<ans->data<<" ";
	    ans=ans->next;
	}
	cout<<endl;
	}
	
	return 0;
}
