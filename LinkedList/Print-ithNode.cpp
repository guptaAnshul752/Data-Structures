// Linked List
// Print ith Node

#include <iostream>
using namespace std;

// Linked List Node Class
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print (Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

void printIthNode (Node *head, int i) {
    Node *temp = head;
    int len =0;
    while(temp!=NULL){
        if(len==i){
            cout<<temp->data;
        }
        len++;
        temp=temp->next;
    }    
}

int main() {
    Node *head = takeinput();
    int pos;
    cout << "Enter Position: ";
    cin >> pos;
    cout << "Node at position " << pos << " is ";
    printIthNode(head, pos);
    return 0;
}
