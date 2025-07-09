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

    bool isIdentical(Node *root1,Node *root2){    //to check identicity
          if(root1==NULL && root2==NULL){
            return true;
          }
          else if(root1==NULL || root2==NULL){
            return false;
          }

         if(root1->data!=root2->data){
            return false;
          }

          return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
    }

    bool IsSubTree(Node *root,Node *subRoot){      //just for checking the head of subroot with root
        if(subRoot==NULL  && root==NULL){
            return true;
        }else if(root==NULL || subRoot==NULL){
            return false;
        }
        if(subRoot->data==root->data){
            if(isIdentical(root,subRoot)){
                return true;
            }
            ;
        }
        int IsLeftSubTree= IsSubTree(root->left,subRoot);
        if(!IsLeftSubTree){
           return IsSubTree(root->right,subRoot);
    }
    return true;
}
    

int main(){
    vector<int>nodes={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    Node *root=buildTrees(nodes);
 cout << "Root (head) of the tree: " << root->data << endl;
     Node* subRoot= new Node(2);
     subRoot->left=new Node(4);
     subRoot->right= new Node(5);
     cout<<IsSubTree(root,subRoot);
}