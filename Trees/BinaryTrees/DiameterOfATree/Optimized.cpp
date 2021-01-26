/*Diameter of Binary Tree 
Given a Binary Tree, find diameter of it.
The diameter of a tree is the number of nodes on the longest path between two end nodes in the tree. 

Example 1:

Input:
       1
     /  \
    2    3
Output: 3
Example 2:

Input:
         10
        /   \
      20    30
    /   \ 
   40   60
Output: 4
Your Task:
You need to complete the function diameter() that takes root as parameter and returns the diameter.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
1 <= Number of nodes <= 10000
1 <= Data of a node <= 1000
The below approach is better as it is bottom up-O(n)
*/
#include <bits/stdc++.h>
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
pair<int,int> calcDiameter(Node *root)
{
    if(root==NULL)
    {
         pair<int,int> p= make_pair(0,0);
         return p;
    }
    pair<int,int> p1=calcDiameter(root->left);
    pair<int,int> p2=calcDiameter(root->right);
    
    pair<int,int> p;
    p.first=max(p1.first,p2.first)+1;
    p.second=max(p1.first+p2.first+1,max(p1.second,p2.second));
    return p;
}
int diameter(Node* root) {
    // Your code here
  pair<int,int> p= calcDiameter(root);
  return p.second;
}
int main(){
       Node *root=new Node();
       buildTree(root);
       cout<<diameter(root);
       return 0;
}
