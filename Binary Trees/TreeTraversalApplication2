// Tree Traversal Applications - 2
// Construct Binary Tree From given InOrder and PostOrder

// Binary Tree Traversals
// InOrder -- L N R
// PostOrder - N L R
// PostOrder- L R N

#include <iostream>
#include <queue>

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

// Construct Tree Helper function
BinaryTreeNode<int>* constructBTreeHelper(int* In, int* Post, int InS, int InE, int PostS, int PostE){

    // BaseCase
    // Empty Array given
    if(InS > InE){
        return NULL;
    }

    // RootData
    int rootData = Post[PostE];

    int rootIndex = -1;
    // Figuring out rootIndex in InOrder
    for (int i = InS ; i <= InE; i++){
        if (In[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    
    // Figuring out 8 important values
    int LInS  = InS;
    int LInE  = rootIndex - 1;
    int LPostS = PostS;
    int LPostE = PostS+1;
    int RInS  = rootIndex + 1;
    int RInE  = InE;
    int RPostE = rootIndex - 1;
    int RPostS = RPostE-RInE+RInS;

    // RootNode Created
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    // Calling this function recursively for left Subtree
    root -> left = constructBTreeHelper(In, Post, LInS, LInE, LPostS, LPostE);
    root -> right= constructBTreeHelper(In, Post, RInS, RInE, RPostS, RPostE);

    return root;
}

// Construct Binary Tree from InOrder and PostOrder
BinaryTreeNode<int>* constructBTree(int* In,int* Post,int size)
{
    return constructBTreeHelper(In, Post, 0, size-1, 0, size-1);
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

  // -1 rePostsents NULL node
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
    cout << endl;
    printLevelWise(root);

    // inOrder Traversal
    cout << endl;
    cout << "InOrder Traversal: ";
    inOrder(root);
    cout << endl;

    // PostOrder Traversal
    cout << endl;
    cout << "PostOrder Traversal: ";
    postOrder(root);
    cout << endl;
    cout << endl;
    int In[] = {4,2,5,1,8,6,9,3,7};
    int Post[]= {4,5,2,8,9,6,7,3,1};

    BinaryTreeNode<int>* root1 = constructBTree(In,Post,9);
    //Printing Tree
    cout << "Binary Tree Built from given Inorder & Postorder is :" <<endl;
    printLevelWise(root1);

    // Deleting
    delete root;
    delete root1;
}
