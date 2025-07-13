
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
int Dist(Node * root, int n){
    if(root==NULL){
        return -1;
    }
    if(root->data==n){
        return 0;
    }
int leftDistance=Dist(root->left,n);
if(leftDistance != -1){
    return leftDistance+1;
}
int rightDistance=Dist(root->right,n);
if(rightDistance!=-1){
    return rightDistance+1;
}
}
int minDist(Node *root,int n1,int n2){
Node *lca=LCA_opti(root,n1,n2);

int D1=Dist(lca,n1);
int D2=Dist(lca,n2);

return D1+D2;
}

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
 int n1=4,n2=5;
 Node * Lca=LCA_opti(root,n1,n2);
 cout<<minDist(root,n1,n2);
      
}