/*Approach #2 (Iterative) [Accepted]
Alternatively, we can solve the problem iteratively, in a manner similar to breadth-first search.

Algorithm

The idea is that we need to swap the left and right child of all nodes in the tree. So we create a queue to store nodes whose left and
right child have not been swapped yet. Initially, only the root is in the queue. As long as the queue is not empty, remove the next node from the queue, 
swap its children, and add the children to the queue. Null nodes are not added to the queue.
Eventually, the queue will be empty and all the children swapped, and we return the original root.

Complexity Analysis

Since each node in the tree is visited / added to the queue only once, the time complexity is O(n), where n is the number of nodes in the tree.

Space complexity is O(n)O, since in the worst case, the queue will contain all nodes in one level of the binary tree.
For a full binary tree, the leaf level has ceil(n/2)=O(n) leaves
*/


class Node{
 public:
  Node* left;
  Node* right;
  int data;
  Node(int d){
  data=d;
  left=NULL;
  right=NULL;
  }
 };
  Node* invertTree(Node* root) {
       if(root==NULL)
           return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* current=q.front();
            q.pop();
            Node *temp=current->left;
            current->left=current->right;
            current->right=temp;
            if(current->left!=NULL)
                q.push(current->left);
            if(current->right!=NULL)
                q.push(current->right);
        }
            
        return root;
    }
 int main(){
    Node *a = new Node(1); 
    a->left = new Node(2); 
    a->right = new Node(3); 
    a->left->left  = new Node(4); 
    a->left->right = new Node(5); 
    Node* invertedTree=invertTree(a);
 }
