/*  We can print postorder traversal without constructing the tree. The idea is, root is always the first item in preorder 
traversal and it must be the last item in postorder traversal. We first recursively print left subtree, then recursively print right subtree.
Finally, print root. To find boundaries of left and right subtrees in pre[] and in[], we search root in in[], all elements before root in in[] 
are elements of left subtree, and all elements after root are elements of right subtree. In pre[], all elements after index of root in in[] are 
elements of right subtree. And elements before index (including the element at index and excluding the first element) are elements of left subtree.
Time Complexity:O(n)
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
void printPostOrder(int preorder[],int inorder[],int start,int end,unordered_map<int,int> mp)
{
    static int index=0;
    if(start>end)
    return;
   //finding the index where preorder[index] occurs in inorder
    int occurrence=mp[preorder[index++]];
    printPostOrder(preorder,inorder,start,occurrence-1,mp);
    printPostOrder(preorder,inorder,occurrence+1,end,mp);
    //Printing the root
    cout<<inorder[occurrence]<<" ";
    
    
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
   printPostOrder(preorder,inorder,0,n-1,mp);


	return 0;
}
