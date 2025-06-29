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
    }

        void Searchitr(int key){
            int idx=0;
         node*temp=head;
           while(temp!=NULL){
            if(temp->data==key){
                cout<<"key is found with address"<<temp->next<<"and idx "<<idx;
                return;
            }
            temp=temp->next;
            idx++;
           }
           cout<<"key not found"<<endl;
        }
    
};
int main(){
    list ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printll();
    ll.Searchitr(9);
}