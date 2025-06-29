#include<iostream>
#include<stack>
using namespace std;
void pAB(stack<int> &s,int value){
       if(s.empty())  {
        s.push(value);
        return;
       }                             //base case
int temp=s.top();
s.pop();
pAB(s,value);
s.push(temp);

}



int main(){
    stack<int>s;

    s.push(3);
    s.push(2);
    s.push(1);
    pAB(s,0);
    while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
}
cout<<endl;
return 0;}