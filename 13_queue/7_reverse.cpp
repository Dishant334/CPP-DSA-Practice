#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void Reverse(queue<int> &q){
  stack<int>s;

  while(!q.empty()){
    s.push(q.front());
    q.pop();
  }

  while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
  }
}
int main(){
    queue<int>q;
    q.push(1);
q.push(2);
q.push(3);
q.push(4);
q.push(5);
q.push(6);
Reverse(q);
}
