// Pre Order Traversal
// Pre Order  --> Root-LeftChild-RightChild

// Post Order Traversal
// Post Order --> LeftChild-RightChild-Root

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>

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
TreeNode<int>* TakeInputLevelWise(){

    //Taking root as input
    int rootdata; // Data in Root Node

    cout <<"Enter the Data in Root: ";
    cin >> rootdata;

    //Root Node Created
    TreeNode<int>* root = new TreeNode<int>(rootdata);

    // Creating a queue
    queue<TreeNode<int>*> pendingNodes;

    // Pushing RootNode to Pending Node
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){

        // Creating a Front Node
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        // Entering No. of child of frontNode
        cout << "Enter the num of child of " << front->data << endl;
        int numChild;
        cin >> numChild;

        for (int i=0 ; i < numChild ;i++){
        int childData;
        cout << "Enter the " << i <<"th child of " << front->data <<endl;
        cin >> childData;

        // Creating a new childNode Dynamically
        TreeNode<int>* child = new TreeNode<int>(childData);

        front->children.push_back(child);
        pendingNodes.push(child);
    }
    }
    return root;
}

void printLevelWise(TreeNode<int>* root) {

    queue<TreeNode<int>*> pending;

    pending.push(root);

    while(pending.size()!=0){

        cout<<pending.front()->data<<":";

        for(int i=0;i<pending.front()->children.size();i++){
            cout<<pending.front()->children[i]->data;
            pending.push(pending.front()->children[i]);

            if(i<pending.front()->children.size()-1){
                cout<<",";
            }
        }
        cout<<endl;

        pending.pop();
    }
}

void preOrder(TreeNode<int>* root){
    if (root == NULL)
        return;
    cout << root->data << " ";

    for (int i=0; i <root->children.size(); i++){
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int>* root) {
    if(root ==NULL){
        return;
    }
    for(int i=0;i<root->children.size();i++){
        postOrder(root->children[i]);
    }
    cout<<root->data<<" ";
}

int main()
{
    // Calling the Input function
    TreeNode<int>* root = TakeInputLevelWise();

    //Calling Print function
    printLevelWise(root);

    //PreOrderTraversal
    cout << "PreOrder Traversal is: "<<endl;
    preOrder(root);
    cout << endl;

    //PostOrderTraversal
    cout << "PostOrder Traversal is: "<<endl;
    postOrder(root);
}



