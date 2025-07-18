#include<iostream>
#include<vector>
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

void RoottoLeaf(Node * root,vector<int>&path){
  if(root==NULL){
    return ;
  }
path.push_back(root->data);

RoottoLeaf(root->left,path);
RoottoLeaf(root->right,path);
if(root->left==NULL && root->right==NULL){
for(int i=0;i<path.size();i++){
  cout<<path[i]<<" ";
}cout<<endl;
}
path.pop_back();
return;
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
  int arr[]={8,5,6,3,1,4,10,11,14};
  int n=sizeof(arr)/sizeof(int);
  Node * root=buildBST(arr,n);
  inorder(root);
  cout<<endl;
  vector<int>path;
  RoottoLeaf(root,path);
}