#include<iostream>
using namespace std;
void printarr(int arr[][3],int n ,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
//odd
void ospiralmatrix(int arr[][3],int n,int m){
    int srow=0;
    int scol=0;
    int erow=n-1;
    int ecol=m-1;
   while(srow<=erow &&scol<=ecol){
    //right
    for(int i=scol;i<=ecol;i++){
        cout<<arr[srow][i]<<" ";
    }
    //down
    for(int j=srow+1;j<=erow;j++){
        cout<<arr[j][ecol]<<" ";
    }
    //left
    for(int i=ecol-1;i>=scol;i--){
        cout<<arr[erow][i]<<" ";
    }
    //up
    for(int j=erow-1;j>=scol+1;j--){
        cout<<arr[j][scol]<<" " ;
    }
    srow++;scol++;
    erow--;ecol--;
}
}
//even
void espiralmatrix(int arr[][3],int n,int m){
    int srow=0;
    int scol=0;
    int erow=n-1;
    int ecol=m-1;
   while(srow<=erow &&scol<=ecol){
    //right
    for(int i=0;i<m;i++){
        cout<<arr[srow][i]<<" ";
    }
    //down
    for(int j=0;j<n;j++){
        cout<<arr[j][ecol]<<" ";
    }
    //left
    for(int i=m-1;i>=0;i--){
        cout<<arr[erow][i];
        if(scol==ecol){
            break;
        }
    }
    //up
    for(int j=n-1;j>=0;j--){
        cout<<arr[j][scol];
        if(srow==erow){
           break;
        }
    }
    srow++;scol++;
    erow--;ecol--;
}}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3;
    int m=3;
    ospiralmatrix(arr,n,m);
}