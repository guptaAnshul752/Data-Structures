// Diameter of BinaryTree (Better Approach)
// heightDiameter function returns both Height and Diameter using Inbuilt Pair Class
// Diameter --> Max distance between 2 nodes.
// New TimeComplexity --> O(n)
// n--> no. of nodes

#include<iostream>
#include<queue>

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

// Print Function
void printLevelWise(BinaryTreeNode<int>* root) {

    queue<BinaryTreeNode<int>*> pending;

    pending.push(root);

    while(pending.size()!=0){


        cout<<pending.front()->data<<":";

        if (pending.front()->left != NULL){
            cout << "L" << pending.front()->left->data << " ";
            pending.push(pending.front()->left);
        }
        if (pending.front()->right != NULL){
            cout << "R" << pending.front()->right->data;
            pending.push(pending.front()->right);
        }

        cout<<endl;

        pending.pop();
        }
    }

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

pair<int,int> heightDiameter(BinaryTreeNode<int>* root){

    // Base Case
    if (root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    // Making pairs for right and left
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns= heightDiameter(root->right);
    int lh = leftAns.first;
    int rh = rightAns.first;
    int ld = leftAns.second;
    int rd = rightAns.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh+rh , max(ld ,rd));
    pair<int,int> ans;
    ans.first = height;
    ans.second = diameter;

    return ans;
}

// Input tree
// 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 9 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int>* root = takeInputLevelWise();

    // Printing
    printLevelWise(root);

    pair<int,int> p = heightDiameter(root);
    // Height of Tree
    cout << "Height of Tree is: " << p.first << endl;

    //Diameter of Tree
    cout << "Diameter of Tree is: " << p.second << endl;

    // Deleting
    delete root;

}

