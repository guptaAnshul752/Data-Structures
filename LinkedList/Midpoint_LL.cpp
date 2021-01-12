// Linked List
// Mid Point of Linked List
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

int length_LL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while(temp!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

Node* midpoint_ll(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    int length = length_LL(head);

    // Even Case
    if (length % 2 == 0){


        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }
    else {

        while(fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }

}
//Method -2
/*
node* midpoint_ll(node *head)
{
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
*/
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
    Node* mid=midpoint_ll(head);
    cout << "The midpoint of the Linked list is: "<<mid->data;


}


