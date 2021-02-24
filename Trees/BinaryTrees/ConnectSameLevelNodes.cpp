/*
Given a binary tree,Print the next right node of all the nodes in a level order manner . 
The next right node is a node which is at the same level with the current node and comes right after the current node in the level order traversal. 
If next right node is null for a particular node,then print -1.

Input Format
The first and the only line contains level order traversal of the given tree . In the level order traversal , -1 represent a null child 
value while any other value represent a node in the tree.

Constraints
1<=number of node in the tree <=10^5

Output Format
Print the next right node of all the nodes in a level order manner.

Sample Input
1 2 3 -1 -1 -1 -1
Sample Output
-1 3 -1 
Explanation
Only node with value 2 has a next right node with value 3.
*/
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* left;
    Node* right;
    int data;
      Node(int d){
          data=d;
          left=NULL;
          right=NULL;
      }
};
void connectSameLevelNodes(Node* root)
{
    if(root==NULL)
    return;
    int lastLevel=-1;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
       Node* n=q.front();
       q.pop();
       if(n!=NULL)
       {
           if(q.front()==NULL)
           {
               cout<<-1<<" ";
           }
           else
           cout<<q.front()->data<<" ";
           if(n->left!=NULL)
           {
               q.push(n->left);
           }
           if(n->right!=NULL)
           {
               q.push(n->right);
           }
       }
       else{
           if(!q.empty())
           {
               q.push(NULL);
           }
       }


    }
}
Node* buildTree()
{
     int x;
     cin>>x;
    Node* root=new Node(x);
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    { 
        Node* n=q.front();
      q.pop();
     int c1,c2;
     cin>>c1>>c2;
       if(c1!=-1)
       {
           n->left=new Node(c1);
           q.push(n->left);
       }
       if(c2!=-1)
       {
           n->right=new Node(c2);
           q.push(n->right);
       }
    }
    return root;

}
int main(){
  
  Node* root=buildTree();
  connectSameLevelNodes(root);
return 0;}
