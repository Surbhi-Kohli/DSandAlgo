/*Input:3 4 -1 6 -1 -1 5 1 -1 -1 -1
Output:
3 
4 5 
6 1 
*/
#include <iostream>
#include<queue>
using namespace std;
class Node{
    
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
         data=d;
         left=NULL;
         right=NULL;
    }
    
};
Node* buildTree(){
    
    int d;
    cin>>d;
  
    if(d==-1)
    return NULL;
    
    Node* root=new Node(d);
    root->left=buildTree();
    root->right=buildTree();
    return root;
    
    
}
void levelOrderBFS(Node *root)
{
      queue<pair<Node*,int>> q;
      int level=0;
      q.push(make_pair(root,level));
      while(!q.empty())
      {
          Node *N=q.front().first;
          int levelOfNode=q.front().second;
           q.pop();
          if(N!=NULL)
          {
         
          if(levelOfNode!=level)
          {
               cout<<endl;
               level++;
          }
           cout<<N->data<<" ";
           
          q.push(make_pair(N->left,level+1));
          q.push(make_pair(N->right,level+1));
          }
          
      }
    
}
int main() {
	Node *root=buildTree();

	levelOrderBFS(root);
	return 0;
}
