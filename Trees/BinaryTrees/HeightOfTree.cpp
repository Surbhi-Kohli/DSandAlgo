/*
Write a Program to Find the Maximum Depth or Height of a Tree

Algorithm:

 maxDepth()
1. If tree is empty then return 0
2. Else
     (a) Get the max depth of left subtree recursively  i.e., 
          call maxDepth( tree->left-subtree)
     (a) Get the max depth of right subtree recursively  i.e., 
          call maxDepth( tree->right-subtree)
     (c) Get the max of max depths of left and right 
          subtrees and add 1 to it for the current node.
         max_depth = max(max dept of left subtree,  
                             max depth of right subtree) 
                             + 1
     (d) Return max_depth
     
Time Complexity of the above algo:O(n)  

Input:3 4 -1 6 -1 -1 5 1 -1 -1 -1
Output:3
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
int heightOfTree(Node *root)
{
     if(root==NULL)
     return 0;
     
     return 1+max(heightOfTree(root->left),heightOfTree(root->right));
    
}
int main() {
	Node *root=buildTree();
	cout<<heightOfTree(root);
	return 0;
}
