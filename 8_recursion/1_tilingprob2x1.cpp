#include<iostream>
using namespace std;
// 2 x n and 2 x 1
int tiling(int n) {
    if(n==1 ||n==0){
        return 1;
    }
    if(n==2){
        return 2;
    }
     //vertical
    int ans1=tiling(n-1);
    //horizontal
    int ans2=tiling(n-2);
    return ans1+ans2;
}
int main(){
cout<<tiling(3)<<endl;
cout<<tiling(4)<<endl;
}