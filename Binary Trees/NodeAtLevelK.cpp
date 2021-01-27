// Print Nodes at Level K
// Base Case is required in Binary Trees

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

// Nodes at level K function
void PrintAtlevelK(BinaryTreeNode<int>* root , int k) {
    // Base Case
    if (root == NULL)
        return;
    if (k==0){
        cout << root->data << " " << endl;
        return;
    }
    PrintAtlevelK(root->left,k-1);
    PrintAtlevelK(root->right,k-1);
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

    // Printing
    printLevelWise(root);

    // Print Nodes at level 2 (i.e 3)
    int k;
    cout << "Enter the Level: ";
    cin >> k;
    cout << "Nodes at level " << k << " are:" << endl;
    PrintAtlevelK(root,k);

    // Deleting
    delete root;
}
