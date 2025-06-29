#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node*next;
    public:
    node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    public:
    node* head;
    node* tail;
    
    list(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        node *newNode=new node(val);
        if(head==NULL){
            tail=head=newNode;
        }
        else{
            newNode->next=head;
            head=newNode;
        } 
    }
    void printll(){
        node *temp=head;
        while(temp != NULL){
           cout<<temp->data<<"->";
           temp=temp->next;     //updation
        }
        cout<<"Null";
        cout<<endl;
    }
    bool isCycle(node *head){
        node* slow=head;
        node* fast=head;

        while(fast !=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"This is a loop ll"<<endl;
                return true;
            }
        }
        cout<<"not a loop ll"<<endl;
        return false;
    }

};
int main(){
    list ll;
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.tail->next=ll.head;
    ll.isCycle(ll.head);
}