// Linked List
// Basic Implementations of Linked List

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

// Function to print Linked List
void print(Node *head)
{
    // Saving value of head by using a temp variable having value same as head
    Node *temp = head;

    while(temp != NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    /*
    temp = head;

    // Printing LL twice
    while(temp != NULL)
    {
        cout << temp->data <<" ";
        temp = temp->next;
    }
    */
    // As we see if we use head itself , at the end of the loop the value of head becomes null
    // so we don't want to loose the value of head so instead created a temp pointer
}
int main()
{
    /// Static creation of node
    // Object of class Node
    Node n1(1);  // data values = 1, ptr = Null
    // Storing address of first node in a variable called head
    Node *head = &n1;

    Node n2(2);
    // Storing address of n2 in next of n1.
    n1.next = &n2;

    Node n3(3);
    n2.next = &n3;

    Node n4(4);
    n3.next = &n4;

    Node n5(5);
    n4.next = &n5;

    // Printing data values of Nodes
    print(head);

    //cout << n1.data << " " << n2.data << " " << n1.data "<<endl;

    // Printing data value of Node1 with help of head pointer
    // cout << head->data <<endl;

    // Printing data value of Node2 with help of head pointer
    // cout << head->next->data <<endl;

    /// Dynamic Creation of node
    /*
    Node *n3 = new Node(10);

    // Storing address of n3 in a head variable
    Node *head1 = n3;

    Node *n4 = new Node(20);

    // Linking 2 nodes
    // No "&" as its already a pointer
    n3->next = n4;

    cout << n3->data << " " << n4->data;
    //cool
    delete n3,n4;
    */
}
