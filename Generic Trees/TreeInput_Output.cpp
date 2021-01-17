// Generic Tree implementation
// Taking Input Recursively
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

//Taking Input Tree Function
TreeNode<int>* TakeInput(){

    //Taking root as input
    int rootdata; // Data in Root Node
    int n; // No. of children

    cout <<"Enter the Root: ";
    cin >> rootdata;

    //Root Node Created
    TreeNode<int>* root = new TreeNode<int>(rootdata);

    cout << "Enter no. of children of " << rootdata <<endl;
    cin >> n;

    for (int i=0 ; i<n ;i++){

        // Creating a new childNode
        TreeNode<int>* child = TakeInput();
        //Linking Nodes of Tree
        root->children.push_back(child);
    }

    return root;
}

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

    //Printing Tree
    for (int i=0; i < root->children.size() ; i++){
         printTree(root->children[i]);
    }

}

int main()
{
    // Calling the Input function
    TreeNode<int>* root = TakeInput();

    //Calling Print function
    printTree(root);

    //TODO delete the tree
    delete root;

}

