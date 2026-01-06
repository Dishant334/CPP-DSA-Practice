#include<iostream>
#include<list>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int V){ //graph of size V
        this->V=V;
        l = new list<int>[V]; //new list of size V
    }
   void addEdge(int src,int v){
      l[src].push_back(v);  //src position pe v add hogya in a list
      l[v].push_back(src);   //v position pe src add hogya in a list 
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
void calcIndegree(vector<int> &indeg){
    for(int i=0;i<V;i++){
        list<int>neighbours=l[i];
        for(int v:neighbours){
             indeg[v]++;
        }
    }
}

void topoSort(){
    vector<int>indeg(V,0);
    calcIndegree(indeg);
    queue<int>q;
    for(int i=0;i<V;i++){
    if(indeg[i]==0){
      q.push(i);
    }}
while(!q.empty()){
    int curr=q.front();
    q.pop();
    cout<<curr<<endl;
    list<int>neighbours=l[curr];
    for(int v:neighbours){
        indeg[v]--;
        if(indeg[v]==0){
            q.push(v);
        }
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
vector<bool>vis(5,false);
 

    return 0;
}