 #include<iostream>
#include<stack>
#include<string>
using namespace std;

void validP(string str){
    stack<char>s;

for(int i=0;i<str.size();i++){
    char c=str[i];
    if(c=='{' || c=='['||c=='('){
        s.push(str[i]);
    }
    else{
        if(s.empty()){
            cout<<"invalid strings"<<endl;
          return;
        }
        else if((c==']'&&s.top()=='[')||(c==')'&&s.top()=='(')||( c=='}'&&s.top()=='{')){
            s.pop();
        }
    }
}
if(s.empty()){
    cout<<"valid parenthesis"<<endl;
}
else{
    cout<<"invalid string"<<endl;
}
}
int main(){
    string str1="{}[]()";
    string str2="{[()]}";
    string str3="({]";
    string str4="]])}";
    string str5="";
    validP(str1);
    validP(str2);
validP(str3);
validP(str4);
    validP(str5);
}