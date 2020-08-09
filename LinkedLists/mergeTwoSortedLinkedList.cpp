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
	int n,m;
	cin>>n;
	
	node *head1;
	int x;
	cin>>x;
	head1=new node(x);
	node *temp=head1;
	for(int i=1;i<n;i++)
	{
	    cin>>x;
	    temp->next=new node(x);
	    temp=temp->next;
	}
	cin>>m;
	node *head2;
	cin>>x;
	head2=new node(x);
	node* temp2=head2;
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
	return 0;
}
