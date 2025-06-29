#include<iostream>
#include<vector>
using namespace std;

class stack{
    public:
    vector <int> vec;
    void push(int val){
        vec.push_back(val);
    }
    void pop(){
        vec.pop_back();
    }
    int top(){
        int lastIDx=vec.size()-1;
        return vec[lastIDx];
    }
    bool isEmpty(){
        if(vec.size()==0){
            return true;
        }
return false;
    }
};
int main(){
    stack s1;
    s1.push(3);
    s1.push(2);
    s1.push(1);
    while(! s1.isEmpty()){
      cout<<s1.top()<<" ";
      s1.pop();
    }
    return 0;
}