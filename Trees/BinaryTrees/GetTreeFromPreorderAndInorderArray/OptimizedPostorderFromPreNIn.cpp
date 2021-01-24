/*
Problem:Construct Tree from given Inorder and Preorder traversals and print postorder traversal
We can optimize the previous esolution using hashing (unordered_map in C++ or HashMap in Java).
We store indexes of inorder traversal in a hash table. So that search can be done O(1) time. 
Time Complexity : O(n)
Input:
5
1 2 4 5 3
4 2 5 1 3
Output:4 5 2 3 1 
*/

#include <iostream>
#include <unordered_map>
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
Node *buildTree(int preorder[],int inorder[],int start,int end,unordered_map<int,int> &mp)
{
    static int index=0;
    if(start>end)
    return NULL;
    Node* root=new Node(preorder[index++]);
    int occurrence=mp[root->data];
    root->left=buildTree(preorder,inorder,start,occurrence-1,mp);
    root->right=buildTree(preorder,inorder,occurrence+1,end,mp);
    
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
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[inorder[i]]=i;
    }
  Node* root= buildTree(preorder,inorder,0,n-1,mp);
  print(root);

	return 0;
}
