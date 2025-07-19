#include<iostream>
#include<vector>
using namespace std;
class Node{
    public: 
    int data;
    Node *left;
    Node*right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};

Node * buildBstfromSorted(int arr[],int si,int ei){
    if(si>ei){
        return  NULL;
    }
int mid=si+(ei-si)/2;
Node * curr=new Node(arr[mid]);
curr->left=buildBstfromSorted(arr,si,mid-1);
curr->right=buildBstfromSorted(arr,mid+1,ei);
return curr;
}
void preorder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int arr[]={3,4,5,6,7,8,9};
    Node *root=buildBstfromSorted(arr,0,6);
    preorder(root);
    return 0;
}