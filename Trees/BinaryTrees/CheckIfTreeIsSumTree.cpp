/*Given a Binary Tree. Check whether it is a Sum Tree or not.

A Binary Tree is a Sum Tree in which value of each node x is equal to sum of nodes present in its left subtree and right subtree . 
An empty tree is also a Sum Tree as sum of an empty tree can be considered to be 0. A leaf node is also considered as a Sum Tree.

Example 1:

Input:
    3
  /   \    
 1     2

Output: 1
Explanation: The given tree is a sum 
tree so return a boolean true.

Example 2:

Input:

          10
        /    \
      20      30
    /   \ 
   10    10

Output: 0
Explanation: The given tree is not a sum
tree. For the root node, sum of elements
in left subtree is 40 and sum of elements
in right subtree is 30. Root element = 10
which is not equal to 30+40.
Below solution runs in O(n) time
*/
pair<bool,int> checkIfSumTree(Node* root)
{
    if(root==NULL)
    {
        return {true,0};
    }
    if(root->left==NULL && root->right==NULL)
    {
        return {true,root->data};
    }
    pair<bool,int> a1=checkIfSumTree(root->left);
    if(a1.first==true)
    {
        pair<bool,int> a2=checkIfSumTree(root->right);
        if(a2.first==true)
        {
            if(a1.second+a2.second==root->data)
            {
                return {true,a1.second+a2.second+root->data};
            }
            else
            return {false,-99};
        }
        else return {false,-99};
    }
    else return {false,-99};
}
bool isSumTree(Node* root)
{
    pair<bool,int> p= checkIfSumTree(root);
    return p.first;
}
