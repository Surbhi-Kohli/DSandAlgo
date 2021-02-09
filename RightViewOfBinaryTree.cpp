/*
Right View of Binary Tree 
Easy Accuracy: 51.66% Submissions: 43596 Points: 2
Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes visible when tree is viewed from right side.

Right view of following tree is 1 3 7 8.

          1
       /     \
     2        3
   /  \     /   \
  4    5   6     7
    \
     8
     
Example 1:

Input:
       1
    /    \
   3      2
Output: 1 2

Example 2:
Input:
     10
    /   \
  20     30
 /   \
40  60 
Output: 10 30 60
*/
vector<int> rightView(Node *root)
{
   vector<int> ans;
   queue<pair<Node*,int>> q;
   if(root!=NULL)
   q.push({root,0});
   int prevLevel=-1;
   while(!q.empty())
   {
      Node* topNode=q.front().first;
      int level=q.front().second;
      q.pop();
      if(level!=prevLevel)
      ans.push_back(topNode->data);
      if(topNode->right)
      {
          q.push({topNode->right,level+1});
      }
      if(topNode->left)
      {
          q.push({topNode->left,level+1});
      }
      prevLevel=level;
   }
   
   return ans;
}
