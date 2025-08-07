#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int>s;

    s.insert(1);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(1);

    cout<<s.size()<<endl;

    if(s.find(3) !=s.end()){
    cout<<"3 exists";
    }else{
        cout<<"3 dne";
    }
}