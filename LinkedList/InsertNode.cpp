// Linked List
/// Insert a Node at index i
// Input Link list from User.
// Improving Complexity
// New Complexity --> O(n)
#include<iostream>

using namespace std;

class Node{
   public:
   int data;
   Node *next;

   // Creating a constructor

   Node(int data)
   {
       this -> data = data;
       next = NULL;
   }
};

// Creating a function of Node type to take input
Node* takeInput_Better()
{
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1)
    {
        Node *newNode = new Node(data);
        if (head==NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;

            tail = tail->next;
            //OR tail=newNode;
        }
       cin >> data;

        }
        return head;
    }

//Function to insert Node at ith position
//Return type is void cause address of head is passed and changes are reflected in main
Node* insertNode(Node *head,int data, int i)
{

    Node *newNode = new Node(data);

    //Method-1
    //Creating a temp variable for storing address of Node at index i-1
    //Creating a 2nd temp variable for storing address of Node at index i
    Node *temp = head;
    int count =0;

    // Condition for Inserting at Index 0
    if (i==0)
    {
        newNode->next = head;
        // Updating head
        head = newNode;
        // Returning updated head to main
        return head;
    }
    while(temp != NULL && count < i-1)
    {
        temp = temp -> next;
        count++;
    }
    // Temp pointer to store address of Node at index i
    if (temp != NULL) {
    Node *a = temp -> next;
    temp->next = newNode;
    newNode->next = a;
    }
    return head;
}
void print(Node *head)
{

    while(head != NULL)
    {
        cout << head->data <<" ";
        head = head->next;
    }
}
int main()
{
    cout << "Enter the data in linked list: ";
    Node *head = takeInput_Better();
    cout << "Linked List is: ";
    print(head);
    cout << "\n";
    // Inserting at ith position
    int data,i;
    cout << "Enter the element you want to insert: ";
    cin>>data;
    cout << "Enter at what Index element should be inserted:";
    cin>>i;

    head = insertNode(head,data,i);
    print(head);


}



