/*Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
The task is to complete the function leftView(), which accepts root of the tree as argument.

Left view of following tree is 1 2 4 8.

          1
       /     \
     2        3
   /   \     /  \
  4     5   6    7
   \
     8  
     
     
    Your Task:
You just have to complete the function leftView() that prints the left view. The newline is automatically appended by the driver code.
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Height of the Tree).

Constraints:
0 <= Number of nodes <= 100
1 <= Data of a node <= 1000
*/


vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   queue<pair<Node*,int>> q;
   int prevLevel=-1;
   if(root!=NULL)
   q.push({root,0});
   while(!q.empty())
   {
       Node* topNode=q.front().first;
       int level=q.front().second;
        q.pop();
       if(prevLevel!=level)
       {
           ans.push_back(topNode->data);
       }
      
       if(topNode->left!=NULL)
       {
           q.push({topNode->left,level+1});
       }
       if(topNode->right)
       {
            q.push({topNode->right,level+1});
       }
       prevLevel=level;
   }
   return  ans;
   
}
