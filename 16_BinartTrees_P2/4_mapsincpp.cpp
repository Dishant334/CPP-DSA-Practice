#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,int>m;
    m[0]=1;
    m[1]=2;
    m[2]=3;
    for(auto it:m){
        cout<<it.first<<","<<it.second<<" ";
    }
    cout<<m.count(3);
}