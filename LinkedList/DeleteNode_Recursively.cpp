// Linked List
// Delete Node from Linked list Recursively
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

Node* delete_R(Node *head, int i) {

    if(head==NULL){
        return head;
    }

    if(i==0){
        Node* temp = head;
        head = temp->next;
        delete(temp);
        return head;
    }

    Node* x= delete_R(head->next,i-1);
    head->next = x;
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
    // Deleting at ith position
    int i;
    cout << "Enter the index of element you want to delete: ";
    cin>>i;
    head = delete_R(head,i);
    cout << "Updated Linked list is: ";
    print(head);


}



