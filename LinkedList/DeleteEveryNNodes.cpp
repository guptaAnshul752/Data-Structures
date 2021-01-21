//Implement kReverse (int k) 
//Reverse first k elements then reverse next k elements and so on

#include <iostream>

using namespace std;

// Node Class
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

// Input LL
node* takeinput() {

    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node* skipMdeleteN(node* head, int M, int N) {
    node* temp = head;
    while(temp!=NULL){
        for(int i=0;i<M-1;i++){
            if(temp!=NULL){
                temp=temp->next;
            }
            else{
                break;
            }
        }
        node* p = temp;
         if(temp==NULL){
            return head;
        }
        for(int j= 0;j<N;j++){
            
            if(temp!=NULL && temp->next!=NULL && p->next!=NULL){
                p=temp->next;
                temp->next=p->next;
                delete(p); 
            }
        }
        temp=temp->next;
   }
    return head;
}

int main()
{
    cout << "Input LL: ";
    node* head=takeinput();
    int m,n;
    cout << "Enter Values of m & n: ";
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    cout << "LL is: ";
    print(head);
    return 0;
}
