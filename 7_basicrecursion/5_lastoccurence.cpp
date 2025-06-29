#include<iostream>
using namespace std;
void lastoccur(int arr[],int num,int target){
    if(arr[num]==target){
        cout<<"the target is found with last index "<<num<<endl;
        return;
    }
    if(num==0){
        cout<<"nothing found";
        return;
    }
    lastoccur(arr,num-1,target);
}
int main(){
    int arr[]={1,2,4,2,5};
    int num=sizeof(arr)/sizeof(int);
    lastoccur(arr,num,2);
}