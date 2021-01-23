/*
Time Complexity:O(n)
*/
#include <iostream>
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
void print(Node *root)
{
    if(root==NULL)
    return;
   
    print(root->left);
     cout<<root->data<<" ";
    print(root->right);
    
}
int main() {
	Node *root=buildTree();

	print(root);
	return 0;
}
