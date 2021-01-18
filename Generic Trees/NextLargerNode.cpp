// Return Node with next Larger element

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

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {

    if (root==NULL){
        return root;
    }
    TreeNode<int> *nextL=NULL;

    if(root->data>n){
        nextL=root;
    }
    for(int i=0;i<root->children.size();i++){
        TreeNode<int> *temp = nextLargerElement(root->children[i], n);
        if(nextL==NULL){
            nextL=temp;
        }
        else if (temp!=NULL && temp->data<nextL->data){
            nextL=temp;
        }
        }
    return nextL;
}

int main()
{
    // Calling the Input function
    TreeNode<int>* root = TakeInputLevelWise();

    //Calling Print function
    printLevelWise(root);

    // Next Larger Node
    int n;
    cout << "Enter the Value: ";
    cin >> n;

    TreeNode<int>* ans = nextLargerElement(root, n);
    if(ans != NULL) {
        cout << "Next Larger Node is : " << ans -> data << endl;
    }
    else {
        cout << INT_MIN << endl;
    }

    //TODO delete the tree
    delete root;
}
