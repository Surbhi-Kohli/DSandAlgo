 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vc;
         queue<TreeNode*> q;
        vector<int> temp;
        int curr_level=0;
           if(root!=NULL)
           {
               q.push(root);
               q.push(NULL);
           }
       while(!q.empty())
       {
           TreeNode* n=q.front();
           q.pop();
           if(n!=NULL)
           {
             temp.push_back(n->val);
               if(n->left!=NULL)
               {
                   q.push(n->left);
               }
               if(n->right!=NULL)
               {
                   q.push(n->right);
               }
            }
           else{
               if(curr_level%2!=0)
                   reverse(temp.begin(),temp.end());
                  
               vc.push_back(temp);
               temp.clear();
               if(!q.empty())
               {
                   q.push(NULL);
               }
               curr_level++;
           }
       }
       
        return vc;
    }
