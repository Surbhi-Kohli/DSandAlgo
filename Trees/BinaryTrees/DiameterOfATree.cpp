/* Diameter of Binary Tree 

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

Naive Approach
 */
 int height(Node *root)
{
    return 1+max(height(root->left),height(root->right));
}
int diameter(Node* root) {
    // Your code here
  if(root==NULL)
  return 0;
   int op1=height(root->left)+height(root->right)+1;
   int op2=diameter(root->left);
   int op3=diameter(root->right);
   int ans=max(op1,max(op2,op3));
  return ans;
}
int main()
{

}
