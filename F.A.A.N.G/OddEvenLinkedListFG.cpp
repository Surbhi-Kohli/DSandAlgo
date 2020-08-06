/*
We are Given a singly linked list, group all odd nodes together followed by the even nodes. Here we are talking about the node number and not the value in the nodes.
Note: i) You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
ii) The relative order inside both the even and odd groups should remain as it was in the input.
iii) The first node is considered odd, the second node even and so on

Input Format
First line contains the number of nodes n. Next line contains the n node numbers.

Constraints
1<=Length of linked list<=10^4

Output Format
Print the original list and the modified list after Grouping all odd nodes together followed by the even nodes.

Sample Input
10
1 2 3 4 5 6 7 8 9 10
Sample Output
Original List: 1 2 3 4 5 6 7 8 9 10 
Modified List: 1 3 5 7 9 2 4 6 8 10 
Explanation
None

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
void arrangeOddEven(Node *head)
{ 
    if(head==NULL)
    return;
    Node *headOdd=head;
    
    Node *odd=head;
    Node *headEven;
    
    Node *even;
    if(head->next!=NULL)
    {headEven=head->next;
        even=head->next;
    }
    while( even!=NULL && even->next!=NULL )
    {
        
        odd->next=even->next;
        odd=odd->next;
        
        even->next=odd->next;
        even=even->next;
        if(even==NULL)
        break;
       
       
    }
  odd->next=headEven;
    Node *tempO=headOdd;
   cout<<"Modified List: ";
    while(tempO!=NULL)
    {
        cout<<tempO->data<<" ";
        tempO=tempO->next;
    }
    
}
int main() {
	int n;
	cin>>n;
     int x;
     cin>>x;
    if(n==1)
	{
	cout<<x;
	return 0;
	}

	Node *head=new Node(x);
	int y;
	cin>>y;
 
	Node *temp=new Node(y);
	head->next=temp;
	for(int i=2;i<n;i++)
	{
	    
	    cin>>x;
	    temp->next=new Node(x);
	    temp=temp->next;
	    
	}

	Node *t=head;
	cout<<"Original List: ";
	if(t!=NULL)
	{
      while(t!=NULL)
	  {
	    	cout<<t->data<<" ";
	    	t=t->next;
	  }
	}
	
cout<<endl;
	arrangeOddEven(head);
	return 0;
}
