// Generic Trees
// Input Tree Level Wise
// Using Inbuilt Queue

#include <iostream>
#include <queue>
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


//Taking Input Tree Level Wise Function
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

void printTree (TreeNode<int>* root)
{
   if(root==NULL)
      return;
      
   cout<<root->data<<": ";
   
   for(int i =0;i<root->children.size();i++){
    cout<<root->children[i]->data<<",";
   }
   
   cout<<endl;
   for(int i =0;i<root->children.size();i++){
    printTree(root->children[i]);
    
   }
}

int main()
{
    // Calling the Input function
    TreeNode<int>* root = TakeInputLevelWise();

    //Calling Print function
    printTree(root);

    //TODO delete the tree
    delete root;
}
