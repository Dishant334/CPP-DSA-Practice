#include<iostream>
#include<vector>
#include<queue>
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


      
    void TreeTreversal(Node *root){
        if(root==NULL){
            return;
        }
      queue <Node*> Q;
    Q.push(root);
    Q.push(NULL);

    while(!Q.empty()){
        Node*curr=Q.front();
         Q.pop();

         if(curr==NULL){                              //for nextline
            cout<<endl;
            if(Q.empty()){
                break;
            }
        Q.push(NULL);
         }
else{
         cout<<curr->data;

         if(curr->left != NULL){
           Q.push(curr->left);
         }
         if(curr->right !=NULL){
            Q.push(curr->right);
         }
       }
      }
    }
    

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
  
    TreeTreversal(root);
}