// Linked List
// Input Link list from User.
// Improving Complexity
// New Complexity --> O(n)
#include<iostream>

#include "Node.cpp"

using namespace std;

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
    Node *head = takeInput_Better();

    print(head);

}
