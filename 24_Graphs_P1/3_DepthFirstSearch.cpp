#include<iostream>
#include<list>
#include<vector>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){ //graph of size V
        this->V=V;
        l = new list<int>[V]; //new list of size V
    }
   void addEdge(int u,int v){
      l[u].push_back(v);  //u position pe v add hogya in a list
      l[v].push_back(u);   //v position pe u add hogya in a list 
   }
   void print(){
   for(int i=0;i<V;i++){
    list<int>neighbours=l[i];  //its the content of neightbour in vertex
    cout<<i<<" : ";
    for(int v:neighbours){
     cout<<v<<" ";
    }
    cout<<endl;
   }    
   }
   void dfs(int u,vector<bool>&vis){
   /* if(vis[u]==true){
        return;
    }*/
    vis[u]=true;
    cout<< u<<" ";
    list<int>neighbours=l[u];

    for(int v:neighbours ){
        if(!vis[v]){   // this is the base case for it
            dfs(v,vis);
        }
    }
     
   }
};

int main(){
 Graph graph(5);

 graph.addEdge(0,1);
 graph.addEdge(1,2);
 graph.addEdge(1,3);
 graph.addEdge(2,3);
 graph.addEdge(2,4); 

 graph.print();
vector<bool>vis(7,false);
 graph.dfs(0,vis);

    return 0;
}