#include<iostream>
#include<string>
using namespace std;

void permutation(string str,string ans){
if(str.size()==0){
    cout<<ans<<endl;
    return;
}
for(int i=0;i<str.size();i++){
   char ch=str[i];
   string rem=str.substr(0,i)+str.substr(i+1);
   permutation(rem,ans+ch); 
}
}
int main(){
    string str="apple";
    string ans=" ";
    permutation(str,ans);
}