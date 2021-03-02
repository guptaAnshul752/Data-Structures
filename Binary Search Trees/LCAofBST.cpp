// LCA -- Lowest Common Ancestor
// LCA of a BST

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

// Take Input Function
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

// LCA Function
int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root==NULL)
        return 0;
    if(root->data==val1 || root->data==val2)
        return root->data;
    int a=0,b=0;
    if(val1<root->data && val2<root->data){
        return lcaInBST(root->left,val1,val2);
    }
    else if(val1>root->data && val2>root->data){
        return lcaInBST(root->right,val1,val2);
    }
    else{
        a=lcaInBST(root->left,val1,val2);
        b=lcaInBST(root->right,val1,val2);
        if(a==0 && b==0)
            return NULL;
        else if(a==0 && b!=0)
            return b;
        else if(a!=0 && b==0)
            return a;
        else
            return root->data;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << lcaInBST(root, a, b);
    delete root;
}
