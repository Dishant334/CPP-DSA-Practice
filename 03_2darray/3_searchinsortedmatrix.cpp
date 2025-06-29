#include<iostream>
using namespace std;
void printarr(int arr[][3],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
//brute force
void Sortedmatrix(int arr[][3],int n,int m,int key){
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(arr[i][j]==key){
            cout<<"key is fount at index "<<i<<" and "<<j<<endl;
            return;
        }
    }
   }
   cout<<"key not found"<<endl;
}
//row/col wise bs
void Bs(int arr[][3],int n,int m,int key){
int srow=0,scol=0;
int erow=n-1,ecol=m-1;

while (scol<=ecol){
for(int i=0;i<n;i++){
    
int mid1=(srow+erow)/2;
int mid2=(scol+ecol)/2;
    if(arr[mid1][scol]==key){
        cout<<"key is found at "<<mid1<<" and "<<scol<<endl;
        return;
    }
    else if(arr[mid1][scol]<key){
        srow=mid1+1;
    }
    else if(arr[mid1][scol]>key){
        erow=mid1-1;
    }

}
scol++;}
cout<<"key is now found"<<endl;
}

//staircase search
void staircase(int arr[][3],int n,int m,int key){
    int i=0,j=m-1;
    while(j>=0&&i<n){
        if(arr[i][j]==key){
            cout<<"key is found at"<<i<<" and "<<j;
            return;
        }
        else if(arr[i][j]<key){
            i++;
        }
        else if(arr[i][j]>key){
            j--;
        }
    }
}
int main(){
    int arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3;
    int m=3;
    printarr(arr,n,m);
    Sortedmatrix(arr,n,m,4);
    Bs(arr,n,m,7);
    staircase(arr,n,m,3);
}