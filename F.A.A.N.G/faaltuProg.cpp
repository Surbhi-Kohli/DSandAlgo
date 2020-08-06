#include <iostream>
#include <vector>
using namespace std;
class Node
{
  public:
  int data;
  Node *next;
  Node(int d){
      data=d;
      next=NULL;
  }
};
void deepCopy(vector<pair<int,int>> vc)
{
    Node *head=new Node(vc[0].first);
//head->next=new Node(vc[vc[0].second].first);
    Node *temp=head; 
    int currIndex=0;
    int i=1;
        cout<<"Old List: ";
        cout<<"("<<vc[0].first<<", ";
    while(i<vc.size())
    {
         temp->next=new Node(vc[vc[currIndex].second].first);
         cout<<vc[vc[currIndex].second].first<<") ";
         
         currIndex=vc[currIndex].second;
         temp=temp->next;
          temp->next=new Node(vc[vc[currIndex].second].first);
        cout<<"("<<vc[vc[currIndex].second].first<<", ";
         currIndex=vc[currIndex].second;
         
        i+=2;
    }
   
    
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int x,y;
	vector<pair<int,int>> vc(n);
	for(int i=0;i<n;i++)
	{  cin>>x>>y;
	
	    vc[i]=make_pair(x,y);
	}
deepCopy(vc);
	return 0;
}
