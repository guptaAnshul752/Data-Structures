// Binary Tree Traversals
// InOrder -- L N R
// PreOrder - N L R
// PostOrder- L R N

#include<iostream>
#include<queue>

using namespace std;

template <typename T>

// Binary TreeNode Class
class BinaryTreeNode{

    public:
        T data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        // Constructor
        BinaryTreeNode(T data){
        this -> data = data;
        left = NULL;
        right = NULL;
        }

        // Destructor
        // First deletes the child den root

        ~BinaryTreeNode(){
        delete left;
        delete right;
        }
};

// InOrder Traversal
void inOrder(BinaryTreeNode<int>* root){
    if (root == NULL)
        return;

    inOrder(root->left);
    cout << root -> data << " " ;
    inOrder(root->right);
}

// PreOrder Traversal
void preOrder(BinaryTreeNode<int>* root){
    if (root == NULL)
        return;

    cout << root -> data << " " ;
    preOrder(root->left);
    preOrder(root->right);
}

// PostOrder Traversal
void postOrder(BinaryTreeNode<int>* root){
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root -> data << " " ;
}

// Print Function
void printLevelWise(BinaryTreeNode<int>* root) {

    queue<BinaryTreeNode<int>*> pending;

    pending.push(root);

    while(pending.size()!=0){

        cout<<pending.front()->data<<":";

        if (pending.front()->left != NULL){
            cout << "L" << pending.front()->left->data << " ";
            pending.push(pending.front()->left);
        }
        if (pending.front()->right != NULL){
            cout << "R" << pending.front()->right->data;
            pending.push(pending.front()->right);
        }

        cout<<endl;

        pending.pop();
        }
    }

// TakeInput Function
BinaryTreeNode<int>* takeInputLevelWise(){

  // For root;
  int rootdata;
  cout << "Enter Root Data: ";
  cin >> rootdata;

  // -1 represents NULL node
  // Not necessarily needed
  if (rootdata == -1){
      return NULL;
  }

  // RootNode Created
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);

  queue<BinaryTreeNode<int>*> pendingNodes;
  pendingNodes.push(root);

  while (pendingNodes.size() != 0){

      // Creating a Front Node
      BinaryTreeNode<int>* front = pendingNodes.front();
      pendingNodes.pop();
      // Left Child
      int LeftData;
      cout << "Enter the left Child of " << front -> data << ": ";
      cin >> LeftData;

      if (LeftData != -1){

      BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(LeftData);
      front->left = leftChild;
      pendingNodes.push(leftChild);

      }

      // Right Child
      int RightData;
      cout << "Enter the right Child of " << front -> data << ": ";
      cin >> RightData;

      if (RightData != -1){

      BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(RightData);
      front->right = rightChild;
      pendingNodes.push(rightChild);
      }
  }
      return root;
}

// Input tree
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    //Printing Tree
    printLevelWise(root);

    // inOrder Traversal
    cout << endl;
    cout << "InOrder Traversal: ";
    inOrder(root);
    cout << endl;

    // preOrder Traversal
    cout << endl;
    cout << "PreOrder Traversal: ";
    preOrder(root);
    cout << endl;

    // postOrder Traversal
    cout << endl;
    cout << "PostOrder Traversal: ";
    postOrder(root);
    cout << endl;

    // Deleting
    delete root;
}
