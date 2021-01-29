 /*
 Since each node in the tree is visited only once, the time complexity is O(n),
 where n is the number of nodes in the tree. We cannot do better than that, since at the very least 
 we have to visit each node to invert it.

Because of recursion, O(h) function calls will be placed on the stack in the worst case, where h is the height of the tree. 
Because h\in O(n)h∈O(n), the space complexity is O(n).
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
 
 Node* invertTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
        Node* Right=invertTree(root->right);
        Node* Left=invertTree(root->left);
        
        root->left=Right;
        root->right=Left;
        return root;
    }
    int main(){
      Node *a = newNode(1); 
    a->left = newNode(2); 
    a->right = newNode(3); 
    a->left->left  = newNode(4); 
    a->left->right = newNode(5); 
    Node* Inverted=invertTree(a);
    }
