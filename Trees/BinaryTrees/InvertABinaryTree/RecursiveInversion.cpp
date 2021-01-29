 
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
