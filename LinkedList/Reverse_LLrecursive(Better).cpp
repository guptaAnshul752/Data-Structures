// Linked List
// Reverse Link list Recursively Better
// TC- O(N)
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

// Creating a class for head and tail ptr for better reverseLL func
class Pair{
    public:

    Node* head;
    Node* tail;

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
// Reverse func. of type Class Pair
Pair reverse_ll2(Node* head)
{
    //BaseCase
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    // Recursive Call
    Pair smallAns = reverse_ll2(head->next);

    smallAns.tail->next = head;
    head->next=NULL;
    Pair ans;
    ans.head=smallAns.head;
    ans.tail=head;
    return ans;
}
// Creating Another function to reverse ll of type Node*
Node* Reverse_Better(Node *head)
{
    return reverse_ll2(head).head;
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
    head = Reverse_Better(head);
    print(head);

}




