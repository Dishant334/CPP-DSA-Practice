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

void inorder(Node * root){
  if(root==NULL){
    return;
  }
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

void PrintinOrder(Node * root, int start,int end){
   if(root==NULL){
    return;
   }
   if(root->data <=end && root->data >= start){
    PrintinOrder(root->left,start,end);
    cout<<root->data<<" ";
    PrintinOrder(root->right,start,end);
   }
   else if(root->data >=end){
    PrintinOrder(root->left,start,end);
   }
   else if(root->data <=start){
    PrintinOrder(root->right,start,end);
   }

}

int main(){
  int arr[]={5,1,3,4,2,7};
  int n=sizeof(arr)/sizeof(int);
  Node * root=buildBST(arr,n);
  inorder(root);
  cout<<endl;
  PrintinOrder(root,2,6);
}