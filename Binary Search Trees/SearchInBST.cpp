// Binary Search Tree
// Return Node whose data matches our search query

#include<iostream>
#include<queue>

using namespace std;

template <typename T>

// BinaryTreeNode Class
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode *left;
        BinaryTreeNode *right;

    // Constructor
    BinaryTreeNode(T data){
    this -> data = data;
    left = NULL;
    right = NULL;
    }

    // Destructor
    ~BinaryTreeNode(){
    delete left;
    delete right;
    }
};

// Take Input Function
BinaryTreeNode<int>* takeInput(){

    // For root;
    int rootData;
    cout << "Enter Data in Root: ";
    cin >> rootData;

    // -1 represents NULL node
    // Not necessarily needed
    if (rootData == -1){
        return NULL;
    }

    // Creating root node
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){

        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        // Left child data
        int leftData;
        cout << "Enter the Left Child of " << front->data <<": ";
        cin >> leftData;
        // Left Node
        if (leftData != -1)
        {
        BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftData);
        // Linking left Node
        front->left = leftChild;
        pendingNodes.push(leftChild);
        }
        // Right child data
        int rightData;
        cout << "Enter the Right Child of " << front->data <<" : ";
        cin >> rightData;
        // Right Node
        if (rightData != -1)
        {
        BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightData);
        // Linking left Node
        front->right = rightChild;
        pendingNodes.push(rightChild);
        }
    }

    return root;
}

// Print function
void printTree(BinaryTreeNode<int>* root) {

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

// Search function Nodes
BinaryTreeNode<int>* SearchNode(BinaryTreeNode<int>* root,int k){
    if (root == NULL){
        return NULL;
    }
    if (root->data == k){
        return root;
    }
    else if ( k > root->data){
        SearchNode(root->right,k);
    }
    else if ( k < root->data){
        SearchNode(root->left,k);
    }
    else{
        return NULL;
    }
}

// Input tree
// 9 5 10 1 6 9 12 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    // Taking Input
    BinaryTreeNode<int>* root = takeInput();

    cout << endl;
    // Printing tree
    printTree(root);

    // Calling Search function
    int k;
    cout << "Enter the Element to find: ";
    cin >> k;

    BinaryTreeNode<int>* ans = SearchNode(root,k);
    //printTree(ans);
    if(ans != NULL) {
        cout << ans -> data << endl;
    }

    // Delete tree
    delete root;
}
