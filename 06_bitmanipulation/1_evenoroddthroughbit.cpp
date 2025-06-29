#include<iostream>
using namespace std;

void evenorodd(int num){
    if(num & 1==1){
        cout<<"the num is odd"<<endl;
    }
    else{
        cout<<"the num is even"<<endl;
    }
}
int main(){
    int num;
    cout<<"enter the num"<<endl;
    cin>>num;
    evenorodd(num);
}