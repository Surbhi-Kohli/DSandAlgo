/*Given a Binary Tree, print the diagonal traversal of the binary tree.

Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to same line.

Example 1:

Input :
            8
         /     \
        3       10
      /   \       \
     1     6       14
         /   \   /
        4     7 13
        
Output : 8 10 14 3 6 7 13 1 4*/

void diagonalPrint(int d,Node* root,map<int,vector<int>> &mp)
{
   if(root==NULL)
   return;
   mp[d].push_back(root->data);
  
   if(root->left)
   {
       diagonalPrint(d+1,root->left,mp);
   }
   
    if(root->right)
   {
       diagonalPrint(d,root->right,mp);
   }
    
}
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    map<int,vector<int>> mp;
   diagonalPrint(0,root,mp);
   for(auto it:mp)
   { // cout<<"for level "<<it.first<<endl;
       vector<int> v=it.second;
       for(auto ii:v)
       {  //  cout<<ii<<" ";
           ans.push_back(ii);
       }
      // cout<<endl;
   }
   return ans;
}
