/*Check if two trees are Mirror
Given two Binary Trees, write a function that returns true if two trees are mirror of each other, else false.

Algo:
For two trees ‘a’ and ‘b’ to be mirror images, the following three conditions must be true:
--Their root node’s key must be same
--Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
--Right subtree of ‘a’ and left subtree of ‘b’ are mirror.

Output:1 (True)
Time Complexity : O(n)
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
bool mirror(Node* a,Node* b)
{
    if(a==NULL && b==NULL)
    return true;
    
    if(a==NULL || b==NULL)
    return false;
    
    if(a->data!=b->data)
    return false;
    
    return a->data==b->data && mirror(a->left,b->right)&&mirror(a->right,b->left);
    
}
int main() {
 Node *a = new Node(1); 
    Node *b = new Node(1); 
    a->left = new Node(2); 
    a->right = new Node(3); 
    a->left->left  = new Node(4); 
    a->left->right = new Node(5); 
  
    b->left = new Node(3); 
    b->right = new Node(2); 
    b->right->left = new Node(5); 
    b->right->right = new Node(4); 
      cout<<mirror(a,b);
	return 0;
}
