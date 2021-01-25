// Check Whether a Binary Tree is Balanced or Not

#include <iostream>
#include <queue>

using namespace std;

template <typename T>

// Binary TreeNode Class
class BinaryTreeNode {
    public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

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

int height(BinaryTreeNode<int>* root){
    int ans=0;
    if(root==NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return 1+max(lh,rh);
}

bool isBalanced(BinaryTreeNode<int> *root) {
    if(root==NULL)
        return true;
    bool ans = true;
    int lh=height(root->left);
    int rh=height(root->right);
    if(lh-rh<=1&&lh-rh>=-1){
        ans = isBalanced(root->left)&&isBalanced(root->right);
    }
    else{
        bool temp=false;
        if(temp==false)
           ans=false;
    }
    return ans;
}

int main() {

    BinaryTreeNode<int>* root = takeInputLevelWise();
    cout << "Is given Binary Tree Balanced?: ";
    if(isBalanced(root))
    	cout << "true" << endl;
    else
	    cout << "false" << endl;
}
