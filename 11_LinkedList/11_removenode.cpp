//find and remove nth node from end

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
    node* head;
    node* tail;
    public:
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
    int size(){
         int size=0;
     node *temp=head;
     while(temp!=NULL){
        size++;
        temp=temp->next;
     }
     return size;
    }

    void removell(int n){
     int len= size(); 
     
     node*prev=head;

     for(int i=0;i<len-n;i++){
        prev=prev->next;
    }

prev->next=prev->next->next;
}};
int main(){
    list ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printll();
    ll.removell(2);
    ll.printll();
}