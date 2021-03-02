// Largest BST Subtree

#include <iostream>
#include <queue>

template <typename T>

using namespace std;

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
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int height(BinaryTreeNode<int> *root){
    if(root==NULL)
        return 0;
    int a= height(root->left);
    int b= height(root->right);
    if(a>=b)
        return a+1;
    else
        return b+1;
}

int  largestBSTSubtree(BinaryTreeNode<int> *root) {
    if(root==NULL)
        return 1;
    int h = height(root);
    int a = largestBSTSubtree(root->left);
    int b = largestBSTSubtree(root->right);
    if(a>b)
        return a;
    else if(b>a)
        return b;
    else if(a==b && a==h-1 && root->left!=NULL && root->right!=NULL && root->left->data<root->data && root->right->data>=root->data)
        return a+1;
    else if(a==b)
        return a;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}
