// Simple Generic tree implementation
// Taking Input Tree
// Outputting Tree Recursively

#include <iostream>
#include <vector>

using namespace std;

template <typename T>

// TreeNode Class
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;  //By default it assumes only Template T type only

    // Constructor to initialize data
    TreeNode(T data){
        this -> data = data;
    }

    // Destructor to deallocate memory
    ~TreeNode(){
    for(int i =0; i<children.size(); i++){
        delete children[i];
    }
    }
};

// Print Tree function
void printTree(TreeNode<int>* root){

    // Edge Case
    if(root == NULL){
        return;
    }
    // Printing Root's data
    cout << root->data << ":";

    //Printing children
    for (int i=0; i < root->children.size() ; i++){
         cout << root->children[i]->data << ",";
    }
    cout << endl;

    //Incorrect way of printing as much details couldn't be derived
    //Printing Tree
    for (int i=0; i < root->children.size() ; i++){
         printTree(root->children[i]);
    }
}

int main() {

    // Creating Node with data elements
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    // Linking Nodes of Tree
    root->children.push_back(node1);
    root->children.push_back(node2);


    // Calling Print function
    printTree(root);

    // Delete the tree
    delete root,node1,node2;

}
