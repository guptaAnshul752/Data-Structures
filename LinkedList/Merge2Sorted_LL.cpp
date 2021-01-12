// Linked List
// Merge 2 sorted Linked List and Final list should be sorted
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


Node* mergeTwoLLs(Node *head1, Node *head2) {
    Node* head = NULL;
    Node* tail = NULL;


    if(head1->data<=head2->data){
        head=head1;
        tail=head1;
        head1=head1->next;
    }
    else{
        head=head2;
        tail=head2;
        head2=head2->next;
    }

    while(head1!=NULL && head2!= NULL){
        if(head1->data<=head2->data){
            tail->next = head1;
            tail=tail->next;
            head1=head1->next;
        }
        else{
        tail->next = head2;
        tail=tail->next;
        head2=head2->next;
        }
    }

    if(head1==NULL){
        tail->next=head2;
    }
    if(head2==NULL){
        tail->next=head1;
    }
    return head;
}
    /*
    while(head1->data != NULL && head2->data != NULL)
    {
        Node *newNode = new Node(data);
         if (head1 < head2)
         {
             fh = head1;
             ft = head1;
             head1 = head1 -> next;
         }
         else if (head1 > head2) {
             fh = head2;
             ft = head2;
             head2 = newNode;
             head2 = head2 -> next;

         }
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
    cout << "Enter the Sorted data in linked list 1: ";
    Node *head1 = takeInput_Better();

    cout << "Enter the  Sorted data in linked list 2: ";
    Node *head2 = takeInput_Better();

    cout << "Linked List 1 is: ";
    print(head1);
    cout << "Linked List 2 is: ";
    print(head2);
    cout << "\n";
    Node *head3 = mergeTwoLLs(head1, head2);
    cout << "The Merged and Sorted Linked List is: ";
    print(head3);



}



