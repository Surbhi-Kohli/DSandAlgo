/*
Given a Binary Tree, write an iterative function to print Preorder traversal of the given binary tree.
 To convert an inherently recursive procedures to iterative, we need an explicit stack. Following is a simple stack based iterative process to print Preorder traversal. 
 1) Create an empty stack nodeStack and push root node to stack. 
2) Do following while nodeStack is not empty. 
   a) Pop an item from stack and print it. 
   b) Push right child of popped item to stack 
   c) Push left child of popped item to stack
Right child is pushed before left child to make sure that left subtree is processed first.
 
 */
 
// C++ program to implement iterative preorder traversal
#include <bits/stdc++.h>
 
using namespace std;
 
/* A binary tree node has data, left child and right child */
class Node {
    public:
    int data;
     Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
 

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(Node* root)
{
    // Base Case
    if (root == NULL)
        return;
 
    // Create an empty stack and push root to it
    stack<Node*> nodeStack;
    nodeStack.push(root);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (nodeStack.empty() == false) {
        // Pop the top item from stack and print it
         Node* node = nodeStack.top();
        cout<<node->data<<" ";
        nodeStack.pop();
 
        // Push right and left children of the popped node to stack
        if (node->right)
            nodeStack.push(node->right);
        if (node->left)
            nodeStack.push(node->left);
    }
}
 
// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
     Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
    iterativePreorder(root);
    //Output:10 8 3 5 2 2 
    return 0;
}
