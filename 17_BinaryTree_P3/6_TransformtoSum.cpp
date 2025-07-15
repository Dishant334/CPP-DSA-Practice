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

    int TransformToSum(Node *root){
        if(root==NULL){
            return 0;
        }

        int LeftOld=TransformToSum(root->left);
        int RightOld=TransformToSum(root->right);
        int currRoot=root->data;
        root->data=LeftOld +RightOld;
        if(root->left !=NULL){
        root->data+=root->left->data;}
       if(root->right !=NULL){
        root->data+=root->right->data;
        }
       
        return currRoot;
    
    }
        
    
     void Preodrder(Node *root){
      if(root == NULL){
         return;
      }

      cout<<root->data<<" ";
      Preodrder(root->left);
      Preodrder(root->right);
    }


int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
 TransformToSum(root);
Preodrder(root);
      
}