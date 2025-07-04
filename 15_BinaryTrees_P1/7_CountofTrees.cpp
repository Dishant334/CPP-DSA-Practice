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
    
    int CountTree(Node* root){
        if(root ==NULL){
            return 0;
        }

        int leftCount=CountTree(root->left);
        int rightCount=CountTree(root->right);

        return leftCount+rightCount+1;       //left count + right count + that head root
    }
int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
 cout<<"The count of the trees is "<<CountTree(root); 
}