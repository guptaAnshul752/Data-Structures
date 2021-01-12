// Linked List
// Length of linked list iterative
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
int main()
{
    cout << "Enter the data values: ";
    Node *head = takeInput_Better();

    print(head);
    cout << "\n";
    cout << "Length of LL is: " << length_LL(head);

}




