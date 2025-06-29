#include<iostream>
using namespace std;

void printOpposite(int num){
    if(num==0){
        cout<<0;
        return;
    }

    cout<<num<<" ";
    printOpposite(num-1);
}

int main(){
    printOpposite(3);
    printOpposite(5);
}