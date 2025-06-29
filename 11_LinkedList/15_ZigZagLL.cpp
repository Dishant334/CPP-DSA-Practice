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
    node* splitatMid(node *head){
        node*slow=head;
        node*fast=head;
        node*prev=NULL;
        while(fast!=NULL &&fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
    prev->next=NULL;}   //righthead
return slow;    
}
    node*reverse(node*head){
        node*prev=NULL;
        node*curr=head;
        node*next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;

            prev=curr;
            curr=next;
        }
      return prev;
    }
    void zigzagLL(node *head){
        node*righthead=splitatMid(head);
        node*rightheadrev=reverse(righthead);

        node *left=head;
        node*right=rightheadrev;
         while(right!=NULL&&left!=NULL){
        node*nextleft=left->next;
        node*rightleft=right->next;
            left->next=right;
            right->next=nextleft;

            left=nextleft;
            right=rightleft;
        }
    }
};
int main(){
    list ll;
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printll();
    ll.zigzagLL(ll.head);
    ll.printll();
}