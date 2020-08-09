/*
Arrange elements in a Linked List such that all even numbers are placed after odd numbers.

Input Format
Enter N space separated Elements

Constraints
None

Output Format
Linked list with all the odd numbers before even numbers

Sample Input
5
1 2 2 2 1
Sample Output
1 1 2 2 2

Sample Input
7
1 2 4 3 8 5 6
Sample Output
1 3 5 2 4 8 6

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
node* oddAfterEven(node*& head,node*& tail)
{ 
 

        node* Even_head = new node(0);
        node* Odd_head = new node(0);

        node* even = Even_head;
        node* odd = Odd_head;

        node* temp = head;

        while(temp != NULL){

            if(temp->data % 2 == 0){
                even->next = temp;
                even = even->next;
            }else{

                odd->next = temp;
                odd = odd->next;
            }

            temp = temp->next;
        }

        odd->next = Even_head->next;
        head = Odd_head->next;
        tail = even;
    tail->next = NULL;
return head;
    
   
}
int main() {

	int n;

      cin>>n;
	
	node *head;
	node *temp;
	node *tail;
	int x;
	if(n>0)
	{	cin>>x;
	head=new node(x);
	 temp=head;
	}
 else head=NULL;
	for(int i=1;i<n;i++)
	{
	   
	   
	    cin>>x;
	     if(i==n-1)
	     {
	         tail=new node(x);
	         tail->next=NULL;
	         temp->next=tail;
	         temp=tail;
	     }
	     else{
	           temp->next=new node(x);
	           temp=temp->next;
	     }
	}
node* ans=oddAfterEven(head,tail);
	while(ans!=NULL)
	{
	    cout<<ans->data<<" ";
	    ans=ans->next;
	}
	return 0;
}
