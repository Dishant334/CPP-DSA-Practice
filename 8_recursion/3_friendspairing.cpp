#include<iostream>
using namespace std;

int pairing(int nfriend){
    if(nfriend==1 || nfriend==0){
        return 1;
    }

    //single friend
    int ans1=pairing(nfriend-1);
    //pair
    int ans2=(nfriend-1)*pairing(nfriend-2);
return ans1+ans2;
}
int main(){
    cout<<pairing(3)<<endl;
    cout<<pairing(4);
}