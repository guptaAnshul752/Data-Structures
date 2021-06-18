// Linked List
// Input Link list from User.
// Complexity = O(n2)
#include<iostream>

using namespace std;

// Node Class
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
Node* takeInput()
{
    int data;
    cin >> data;

    Node *head = NULL;

    // -1 points that no further data to be taken as input
    while(data != -1)
    {
        Node *newNode = new Node(data);
        if (head==NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp=head;
            while(temp->next != NULL)
            {
                temp = temp -> next;
            }
            temp->next = newNode;
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
    Node *head = takeInput();

    print(head);
}
