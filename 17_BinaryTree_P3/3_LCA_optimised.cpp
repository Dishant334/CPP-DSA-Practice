
#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node *left;    //for left child
    Node *right;   //for right child
 
    Node(int data){
        this->data=data;
         left=right=NULL;
    }
};

     static int idx = -1;
    Node *buildTrees(vector<int> &nodes){
      idx++;
      if(nodes[idx]==-1){
        return NULL;
      }
    Node*currNode=new Node(nodes[idx]);
    currNode->left=buildTrees(nodes);
    currNode->right=buildTrees(nodes); 

    return currNode;
    }
    
Node * LCA_opti(Node * root,int n1,int n2){
if (root==NULL){
    return NULL;
}
if(root->data==n1 || root->data==n2){
    return root;
}
Node* Le=LCA_opti(root->left,n1,n2);
Node* Ri=LCA_opti(root->right,n1,n2);

if(Le==NULL && Ri==NULL){
    return NULL;
}

if(Le!=NULL && Ri==NULL){
    return Le;
}
if(Ri!=NULL && Le==NULL){
    return Ri;
}
if(Ri!=NULL && Le!=NULL){
    return root;
}
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
 int n1=4,n2=5;
 Node * Lca=LCA_opti(root,n1,n2);
 cout<<Lca->data;
      
}