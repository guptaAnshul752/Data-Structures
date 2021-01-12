// Linked List
// Reverse Link list Recursively
// TC- O(N2)
#include<iostream>

using namespace std;
// Node Creation
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

Node* reverse_ll(Node* head)
{
    //BaseCase
    if(head == NULL || head->next == NULL){
        return head;
    }
    // Recursive Call
    Node *smallAns = reverse_ll(head->next);

    // Temp ptr for Storing address of last element of reversed LL
    Node *temp = smallAns;

    while(temp->next != NULL){
        temp = temp -> next;
    }
    temp -> next = head;
    head -> next = NULL;
    return smallAns;

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
    cout << "Enter the data in Linked List : ";
    Node *head = takeInput_Better();
    cout<<"\n";
    cout << "Reversed Linked List is: ";
    head = reverse_ll(head);
    print(head);

}



