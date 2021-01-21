// Simple Binary Tree Implementation

#include<iostream>

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

// Print Function
void printTree(BinaryTreeNode<int>* root){
    // Base Case
    if (root==NULL)
        return;

    cout << root->data << ":";

    if (root->left != NULL){
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL){
        cout << "R" << root->right->data<< " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);

}

// TakeInput Function
BinaryTreeNode<int>* takeInput(){

  // For root;
  int rootdata;
  cout << "Enter Data: ";
  cin >> rootdata;

  // -1 represents NULL node
  if (rootdata == -1){
      return NULL;
  }

  // RootNode Created
  BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);

  // Left Child
  BinaryTreeNode<int>* leftChild = takeInput();
  // Left Child
  BinaryTreeNode<int>* rightChild = takeInput();

  root->left = leftChild;
  root->right = rightChild;

  return root;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();

    // Printing
    printTree(root);

    // Deleting
    delete root;
}
