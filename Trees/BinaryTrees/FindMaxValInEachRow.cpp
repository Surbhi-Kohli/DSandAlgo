/*
Given the level order traversal of a binary tree , Print the maximum value in each row of the given binary tree.

Input Format
First line contains level order traversal of the tree.The values in the input are in the order of level order traversal of the tree where,
an positive integer denotes node values, and a -1 denotes NULL child.

Constraints
1<=number of nodes in the tree <=10^5

Output Format
Print the maximum value in each row of the binary tree.

Sample Input
1 2 3 4 5 6 7 -1 -1 -1 -1
Sample Output
1 3 7
Explanation
For first row, 1 is the maximum value.
For second row,3 is the maximum value.
For third row,7 is the maximum value.
So,we print 1 3 7
*/
#include <bits/stdc++.h>
using namespace std;
class Node{
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
void maxValueInRow(Node* root)
{
    queue<pair<Node*,int>> q;
    int levelTillNow=0;
  map<int,int> mp;
    if(root!=NULL)
    {
      // cout<<root->data<<" ";
       q.push({root,0});
    }
    while(!q.empty())
    {
      pair<Node*,int> p=q.front();
       int level=p.second;
     //  cout<<"level "<<level<<" for "<<p.first->data<<endl;
       Node* n=p.first;
       q.pop();
       
           if(mp[level]<n->data)
             mp[level]=n->data;
       
        if(n->left)
        {
            q.push({n->left,level+1});
        }
        if(n->right)
        {
            q.push({n->right,level+1});
        }
      //  levelTillNow=level;
    }
    for(auto it: mp)
    {
        cout<<it.second<<" ";
    }
}
Node* levelOrderTraversal()
{
    int d;
    cin>>d;
    queue<Node*> q;
    Node* root;
    if(d!=-1)
    {
      root=new Node(d);
      q.push(root);
    }
    while(!q.empty())
    {
        Node* n=q.front();
        q.pop();
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            n->left =new Node(c1);
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
   Node* r=levelOrderTraversal();
   maxValueInRow(r);
return 0;
}
