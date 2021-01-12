// Linked List
// Length of LL recursive
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
    if (head==NULL){
        return 0;
    }
    else{
        return 1+length_LL(head->next);
    }
}
int main()
{
    cout << "Enter the data values: ";
    Node *head = takeInput_Better();

    print(head);
    cout << "\n";
    cout << "Length of LL is: " << length_LL(head);

}



