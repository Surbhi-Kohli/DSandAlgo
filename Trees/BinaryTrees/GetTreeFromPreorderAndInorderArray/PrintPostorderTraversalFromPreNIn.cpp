/*
Problem: Construct Tree from given Inorder and Preorder traversals and then print postorder traversal

Algorithm: buildTree() 
1) Pick an element from Preorder. Increment a Preorder Index Variable (preIndex in below code) to pick next element in next recursive call. 
2) Create a new tree node tNode with the data as picked element. 
3) Find the picked element’s index in Inorder. Let the index be inIndex. 
4) Call buildTree for elements before inIndex and make the built tree as left subtree of tNode. 
5) Call buildTree for elements after inIndex and make the built tree as right subtree of tNode. 
6) return tNode.
Time Complexity:O(n^2);
Worst case occurs when tree is left-skewed
Example Preorder and Inorder traversals for worst case are {A, B, C, D} and {D, C, B, A}.
In the left skewed tree,search operation will be costly as it will be applied on major part of inorder array.
Input:
5
1 2 4 5 3
4 2 5 1 3
Output: 4 5 2 3 1
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
int search(int inorder[],int key,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==key)
        return i;
    }
    return -1;
}
Node *buildTree(int preorder[],int inorder[],int start,int end)
{
    static int index=0;
    if(start>end)
    return NULL;
    Node* root=new Node(preorder[index++]);
    int occurrence=search(inorder,root->data,start,end);
    root->left=buildTree(preorder,inorder,start,occurrence-1);
    root->right=buildTree(preorder,inorder,occurrence+1,end);
    
    return root;
    
}
void print(Node *root)
{
    if(root==NULL)
    return;
   
    print(root->left);
    print(root->right);
     cout<<root->data<<" ";
}
int main() {
    int n;
    cin>>n;
    int preorder[n];
    int inorder[n];
    for(int i=0;i<n;i++)
    {
        cin>>preorder[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>inorder[i];
    }
  Node* root= buildTree(preorder,inorder,0,n-1);
  print(root);

	return 0;
}
