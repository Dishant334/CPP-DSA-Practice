#include<iostream>
using namespace std;
void reverse(int *arr,int n,int *rev){
int i=n-1;
for(int j=0;j<n;j++){
    rev[j]=arr[i--];
   cout<<rev[j]<<","; 
}  
}
int main(){
    int arr[]={1,2,4,2};
    int rev[4];
    int n=4;
    reverse(arr,n,rev);
}