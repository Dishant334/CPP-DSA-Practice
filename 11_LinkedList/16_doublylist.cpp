//implementing doubly linked list,pop_front,push_front

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    node*prev;

    node(int val){
        data=val;
        prev=next=NULL;
    }
};
class doublylinkedlist{
    public:
    node *head;
    node*tail;

    doublylinkedlist(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        node *newNode=new node(val);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }
    void pop_front(){
     node*temp=head;
     node*temp2=head->next;
     head->next=NULL;
     temp2->prev=NULL;
     head=temp2;
     temp=NULL;

    }
    void printlist(){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL";
        cout<<endl;
    }
};

int main(){
    doublylinkedlist dll;
    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);
    dll.pop_front();
    dll.printlist();
}