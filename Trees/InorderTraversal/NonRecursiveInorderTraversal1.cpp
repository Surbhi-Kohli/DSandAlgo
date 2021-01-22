/*Using Stack is the obvious way to traverse tree without recursion. Below is an algorithm for traversing binary tree using stack. 
See this for step wise step execution of the algorithm.

1) Create an empty stack S.
2) Initialize current node as root
3) Push the current node to S and set current = current->left until current is NULL
4) If current is NULL and stack is not empty then 
     a) Pop the top item from stack.
     b) Print the popped item, set current = popped_item->right 
     c) Go to step 3.
5) If current is NULL and stack is empty then we are done.

Input:3 4 -1 6 -1 -1 5 1 -1 -1 -1
Output:4 6 3 1 5
Time Complexity:O(n)
Space Complexity:O(n)
*/

#include <iostream>
#include <stack>
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
void printInorder(Node *root)
{
     stack<Node*> st;
    Node *curr=root;
    while(curr!=NULL || st.empty()==false)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr=curr->left;
        }
        curr=st.top();
        st.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    
}
int main() {
	Node *root=buildTree();

	printInorder(root);
	return 0;
}
