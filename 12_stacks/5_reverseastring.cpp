#include<iostream>
#include<stack>

using namespace std;


string reverse(stack<char> &s,string str){
    string ans;
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        ans+=s.top();
        s.pop();
    }
    return ans;
}
int main(){
stack<char>s;
string str="abcd";
cout<<reverse(s,str);
}