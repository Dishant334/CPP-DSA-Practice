#include<iostream>
using namespace std;

class Node{
  public:

  int data;
  Node * left;
  Node * right;

  Node(int val){
    data=val;
    left=NULL;
    right=NULL;
  }
};
Node *insert(Node * root,int val){
if(root ==NULL){
  root=new Node(val);
  return root;
}

if(val<root->data){
root->left=insert(root->left,val);
}
else if(val>root->data){
root->right=insert(root->right,val);
}
return root;
}

Node* buildBST(int arr[],int n){
Node * root=NULL;
for(int i=0;i<n;i++){
  root=insert(root,arr[i]);
}
return root;
}


Node * IoS(Node * root){
      while(root->left!=NULL){
        root=root->left;
      }
        return root;
    }


Node * delNode(Node * root,int val){
    if(root ==NULL){
        return NULL;
    }
    if(val < root->data){
        root->left= delNode(root->left,val);
    }
    if(val > root->data){
       root->right= delNode(root->right,val);
    }
    
    if(val == root->data){
       //case 1   no childer
       if(root->left == NULL && root->right == NULL){
        delete root;
         return NULL;
       }
       //case 2  1 children
       else if(root->left ==NULL || root->right==NULL){
        if(root->left ==NULL){
            delete root;
           return root->right;
        }else if(root->right ==NULL){
            delete root;
            return root->left;
        }
       }
        //case 3 2 children
       else{
         Node * IS=IoS(root->right);
          root->data=IS->data;
         root->right= delNode(root->right,IS->data);   //depending on case 1 or 2 it delete this node

       }
       return root;
    }
    return root;
}

void inorder(Node * root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main(){
  int arr[]={5,1,3,4,2,7};
  int n=sizeof(arr)/sizeof(int);
  Node * root=buildBST(arr,n);
  cout<<"Original tree"<<endl;
  inorder(root);
  cout<<endl;
  delNode(root,5);
  cout<<"After delete tree"<<endl;
  inorder(root);
}