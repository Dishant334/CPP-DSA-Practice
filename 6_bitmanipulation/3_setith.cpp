#include<iostream>
using namespace std;

int setith(int val,int pos){
    return val | 1<<pos;
}

int main(){
    cout<<setith(6,2);
}
