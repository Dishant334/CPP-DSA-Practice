#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

class Node{
    public:
    Node * next;
    int val;
    string key;

    Node(string key,int val){
        next=NULL;
        this->key=key;
        this->val=val;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

class HashTable {
    int totSize;
    int currSize;  //for rehashing
    Node ** table;
    public:
    HashTable(int size=5){   //default=5
        totSize=size;
        currSize=0;

        table=new Node * [totSize];   //creates a table
    for(int i=0;i<totSize;i++){
        table[i]=NULL;    //initializing all with null
    }
    }

    int hashFunction(string key){
         int idx=0;

         for(int i=0;i<key.size();i++){
            idx=idx+ (key[i]*key[i])%totSize;   //we take mod on each step to prevent overflow
         }
     }
     void rehash(){    //O(n)
          Node** oldTable=table;
          int olSize=totSize;

          totSize=2*totSize;
          table=new Node *[totSize];
          
          for(int i=0;i<totSize;i++){
            table[i]=NULL;
          }

          for(int i=0;i<totSize;i++){
            Node * temp= oldTable[i];
            while(temp !=NULL){
                insert(temp->key,temp->val);
                temp=temp->next;
            }

            if(oldTable[i]!=NULL){
                delete oldTable;
            }
          }
          delete[] oldTable;
     }
void insert(string key,int val){
    int idx=hashFunction(key);   //returns idx in int for a key

    Node* newNode=new Node(key,val); 
    Node* head=table[idx];

    newNode->next=head;
    head=newNode;
    currSize++;

    double lambda=currSize/(double)totSize;
    if(lambda >1){
        rehash();  //O(n)
    }
}
};


int main(){
    HashTable ht(6);

    return 0;
}