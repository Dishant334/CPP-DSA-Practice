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

    int KthAncestor(Node * root,int node,int k){
    if(root==NULL){
      return -1;
    }

    if(root->data==node){
      return 0;
    }
    int LeftDist=KthAncestor(root->left,node,k);
    int RightDist=KthAncestor(root,node,k);

    if(LeftDist ==-1 && RightDist ==-1){
       return -1;
    }

    int validVal=LeftDist ==-1?RightDist :LeftDist;

    if(validVal +1 ==k){
      cout<<"kth Ancestor :"<<root->data;
    }

    return validVal+1;
    }    

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
 cout<<KthAncestor(root,5,2);
      
}