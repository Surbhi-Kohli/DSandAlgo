/*
We are given a linked list which contains a cycle. Detect that cycle and break it. Print the linked list after removing the cycle.

Input Format
The first line contains space separated integers. The integers are such that all the values are distinct but the value start
repeating once the cycle gets completed. The list of integers given ends when -1 is input.

Constraints
n < 10^5 where n is the length of list without the cycle

Output Format
Output single line containing space separated integers representing the list

Sample Input
1 2 3 4 5 2 3 -1
Sample Output
1 2 3 4 5

Explanation
Initially the first five elements are unique but starts repeating from 2. This means there is a link from 5 back to 2. So it 
represents a cycle. We have to break this cycle and print the list after breaking the cycle.

Sample Input //Important
1 2 1 -1
Sample Output
1 2

Sample Input
1 2 3 4 5 6 7 2
Sample Output
1 2 3 4 5 6 7
*/
#include<iostream>
#include <unordered_map>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int d)
	{
		data=d;
		next=NULL;
	}
};
Node* cycleDetectionInLinkedList(Node *&head)
{  //cout<<"in function "<<endl;
        Node *slow=head;
	Node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
   {
	   fast=fast->next->next;
	   slow=slow->next;
	   Node *prev=NULL;
	  if(fast==slow)
	   {
		
		   slow=head;
                   while(slow!=fast)
		  {
			  prev=fast;
			  fast=fast->next;
			  slow=slow->next;
		  }
		  if(prev!=NULL)
		  prev->next=NULL;
		  else //prev will be NULL like in test case 1->2->1
		  fast->next->next=NULL;
	   }
   }
   return head;
}

int main() {
    int x;
	Node * head=NULL;
        unordered_map<int,Node*> mp;
	cin>>x;
	//cout<<x<<"is value of x"<<endl;
	head=new Node(x);
	Node *temp=head;
       mp[x]=head;

	cin>>x;
	while(x!=-1)
	{ 
	   if(mp.find(x)==mp.end())
	   {
            temp->next=new Node(x);
	    temp=temp->next;
	      mp[x]=temp;
	  }
	  else{
		  temp->next=mp[x];
	  }
	    cin>>x;
	}
	Node* ans=cycleDetectionInLinkedList(head);
	while(ans!=NULL)
	{
		cout<<ans->data<<" ";
		ans=ans->next;
	}
	return 0;
}
