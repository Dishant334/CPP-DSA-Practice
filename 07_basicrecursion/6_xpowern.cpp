#include<iostream>
using namespace std;
int xpown(int x,int num){
    if(x==1 || num==0){
        return 1;
    }
    if(x==0){
        return 0;
    }
    return x * xpown(x,num-1);
}
int main(){
    cout<<xpown(3,3)<<endl;
    cout<<xpown(1,0)<<endl;
    cout<<xpown(8,0)<<endl;
    cout<<xpown(2,10)<<endl;
}