// Height of BinaryTree
// Height --> No. of Levels in a Tree

#include<iostream>
#include<queue>

using namespace std;

template <typename T>

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

// Return Height Function
int heightTree(BinaryTreeNode<int>* root){

    // Base Case
    if (root == NULL)
        return 0;
    return 1 + max(heightTree(root->left) ,heightTree(root->right));
}

// Input tree
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    // Printing
    printLevelWise(root);

    //Height of Tree
    cout << "Height of Tree is: " << heightTree(root);

    // Deleting
    delete root;
}
