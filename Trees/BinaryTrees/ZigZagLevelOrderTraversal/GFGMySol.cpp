vector <int> zigZagTraversal(Node* root)
{
    vector<int>  ans;
    vector<int> temp;
    queue<pair<Node*,int>> q; 
   int level=0;
    if(root!=NULL)
    {
         q.push({root,0});
         
    }
    while(!q.empty())
    {
        pair<Node*,int> p=q.front();
        q.pop();
        Node* n=p.first;
        int nodeLevel=p.second;
        if(level!=nodeLevel)
        {
            if(level%2!=0)
            {
                reverse(temp.begin(),temp.end());
            }
            for(int i=0;i<temp.size();i++)
            {
                ans.push_back(temp[i]);
            }
            temp.clear();
        }
        temp.push_back(n->data);
        level=nodeLevel;
        if(n->left!=NULL)
        {
            q.push({n->left,nodeLevel+1});
        }
        if(n->right!=NULL)
        {
            q.push({n->right,nodeLevel+1});
        }
    }
   
    if(temp.size()!=0)
    {
        if(level%2!=0)
        reverse(temp.begin(),temp.end());
          for(int i=0;i<temp.size();i++)
            {
                ans.push_back(temp[i]);
            }
            temp.clear();
    }
    return ans;
}
