// Binary Search Tree Class
// Perform Operation -- 1. Insert
//                      2. Delete
//                      3. Check if Node contains any data

#include "BinaryTreeNode.h"
#include<iostream>

using namespace std;

class BST {

    //private
    BinaryTreeNode<int>* root;

    public:
    // Constructor
    BST(){
    root = NULL;
    }
    // Destructor
    ~BST(){
    delete root;
    }

    //M-1 --> Deletion
    //Private Delete Data Helper Function
    private:
    BinaryTreeNode<int>* deleteDataH(int data,BinaryTreeNode<int>* node){

    // BaseCase
    if (node == NULL){
        return NULL;
    }
    // Condition for left
    if (data < node->data){
        node->left = deleteDataH(data,node->left);
        return node;
    }
    // Condition for right
    else if (data > root->data){
        node->right = deleteDataH(data,node->right);
        return node;
    }
    else{
        // Leaf Node
        if ((node->left == NULL) && (node->right == NULL)){
            delete node;
            return NULL;
        }
        // Left Node is NULL
        else if ((node->left == NULL && node->right != NULL)){
            BinaryTreeNode<int>* temp = node->right;
            node->right = NULL;
            delete node;
            return temp;
        }
        // Right Node is NULL
        else if ((root->left != NULL && root->right == NULL)){
            BinaryTreeNode<int>* temp = node->left;
            node->left = NULL;
            delete node;
            return temp;
        }
        // Parent Node
        else {
            // Picking smallest of right as Replacement for root
            BinaryTreeNode<int>* minNode = root->right;
            while (minNode->left != NULL){
                minNode = minNode->left;
            }
            int rightMin = minNode->data;
            node->data = rightMin;
            node->right = deleteDataH(rightMin,node->right);
            return node;
        }
    }
    }

    // PrintTree
    void printTreeH(BinaryTreeNode<int>* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data << ":";
		if (root->left != NULL) {
			cout << "L:" << root->left->data<<",";
		}

		if (root->right != NULL) {
			cout << "R:" << root->right->data;
		}
		cout << endl;
		printTreeH(root->left);
		printTreeH(root->right);
	}

    public:
    void deleteData(int data){
        this->root = deleteDataH(data,root);

    }

    void printTree() {
		printTreeH(root);
	}

    //M-2 --> Insertion
    //Private Helper Function
    private:
    BinaryTreeNode<int>* insertDataH(int data, BinaryTreeNode<int>* node){

    // BaseCase
    if (node == NULL){
        BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
        return newNode;
    }
    // Condition for left
    if (data < node->data){
        node->left = insertDataH(data,node->left);
    }
    // Condition for right
    else if (data > root->data){
        node->right = insertDataH(data,node->right);
    }
    return node;
    }

    public :
    void insertData(int data){
        this->root = insertDataH(data,root);
    }

    //M-3 --> Check Data present or not
    //Private helper function
    private:
    bool hasDataH(int data,BinaryTreeNode<int>* node){

        // BaseCase
        if (node == NULL){
            return false;
        }

        if (node->data == data){
            return true;
        }
        else if (node->data > data){
            return hasDataH(data,node -> left);
        }
        else {
            return hasDataH(data,node->right);
        }
    }

    public :
    bool hasData(int data){
        return hasDataH(data,root);
    }
};
