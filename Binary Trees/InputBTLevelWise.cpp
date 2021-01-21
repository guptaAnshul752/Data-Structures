// Binary Tree Implementation Input LevelWise

#include<iostream>
#include<queue>

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

// TakeInput LevelWise Function
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

int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    // Printing
    printTree(root);

    // Deleting
    delete root;

}
