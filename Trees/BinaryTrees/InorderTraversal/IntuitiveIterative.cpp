/*Super intuitive Inorder traversal O(n) time and space*/
#include <iostream>
#include <stack>
using namespace std;
class Node 
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int item) 
    {
        data = item;
        left = NULL;
        right=NULL;
    }
};
void postOrder(Node *root)
{
    stack<pair<Node*,int>> st;
    st.push({root,0});
    
    while(!st.empty())
    {
        Node* curr=st.top().first;
        int count=st.top().second;
        if(curr==NULL)
        {
            st.pop();
            continue;
        }
        else if(count==0)
        {
            st.pop();
            st.push({curr,1});
            st.push({curr->left,0});
        }
        else if(count==1)
        {
            st.pop();
            st.push({curr,2});
             cout<<curr->data<<" ";
           
        }
        else if(count==2)
        {
           
            st.pop();
            st.push({curr,3});
             st.push({curr->right,0});
        }
        else if(count==3)
        st.pop();
    }
}

int main() {
    
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 
    postOrder(root); //4 2 5 1 6 3 7 

	return 0;
}
