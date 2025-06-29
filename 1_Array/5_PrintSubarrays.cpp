#include<iostream>
using namespace std;
void Subarray(int arr[],int n){
    int maxsum=arr[0];
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
             int sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
                cout<<arr[k]<<" ";
            }
            cout<<":"<<sum;
            maxsum=max(maxsum,sum);
            cout<<endl;
        }
    }
    cout<<"the max is :"<<maxsum;
}
int main(){
    int arr[]={1,2,-3,2,5};
    int n=sizeof(arr)/sizeof(int);
    Subarray(arr,n);
}