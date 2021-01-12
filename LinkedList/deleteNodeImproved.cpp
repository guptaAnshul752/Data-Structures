// Linked List
/// Deleting a Node at index i
// Input Link list from User.

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

//Function to delete Node at ith index
Node* deleteNode(Node *head, int i)
{

    Node *temp = head;
    int count =0;


    // Condition for Deletion at Index 0
    if (i==0)
    {
        Node *a = temp->next;
        // Updating head
        head->next = a;
        // Returning updated head to main
        return head;
        delete a;
    }
    while(temp != NULL && count < i-1)
    {
        temp = temp -> next;
        count++;
    }

    if (temp != NULL) {
    Node *a = temp -> next;
    Node *b = a -> next;
    temp -> next = b;
    delete a;
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
    int i;
    cout << "Enter at what Index element should be deleted:";
    cin>>i;

    deleteNode(head,i);
    print(head);


}





