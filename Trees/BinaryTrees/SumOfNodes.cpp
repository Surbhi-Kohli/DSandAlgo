/*
Sum of all nodes in a binary tree

Input:3 4 -1 6 -1 -1 5 1 -1 -1 -1
output:19*/
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
int sumNodesOfTree(Node *root)
{
     if(root==NULL)
     return 0;
     
     return root->data+sumNodesOfTree(root->left)+sumNodesOfTree(root->right);
    
}
int main() {
	Node *root=buildTree();

	cout<<sumNodesOfTree(root);
	return 0;
}
