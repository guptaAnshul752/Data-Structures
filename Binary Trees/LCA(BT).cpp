// LCA (Lowest Common Ancestor)

#include <iostream>
#include <queue>

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

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter root data : ";
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
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2) {
    if(root==NULL)
        return NULL;
    if(root->data==val1 || root->data==val2){
        return root->data;
    }
    int a = lcaBinaryTree(root->left,val1,val2);
    int b = lcaBinaryTree(root->right,val1,val2);
    if(a==NULL && b==NULL)
        return NULL;
    else if(a==NULL && b!=NULL){
        return b;
    }
    else if(a!=NULL && b==NULL){
        return a;
    }
    else{
        return root->data;
    }
}

int main() {

    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cout << "Enter the values of Nodes: ";
    cin >> a >> b;
    cout << "LCA : " << lcaBinaryTree(root, a, b);
    delete root;
}
