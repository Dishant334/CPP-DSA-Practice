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

    void insert(int val,int pos){
     node*insertNode=new node(val);
     node*prev=head;
      for(int i=0;i<pos-1;i++){         //to access prev-1 ll
        prev=prev->next;
        if(prev==NULL){
           cout<<"position is invalid"<<endl;
           return;
        }   
      }
        insertNode->next=prev->next;
        prev->next=insertNode;
      
     
    }
};
int main(){
    list ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printll();
    ll.insert(100,3);
    ll.printll();
}