#include<iostream>
using namespace std;
void diagonalsum(int arr[][3],int n,int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i][i];
        if(i!=n-i-1){     //only for middle one like for n=3 1,1 should not be repeated
            sum+=arr[i][n-i-1];
        }
    }
    cout<<sum;

}
int main(){
    int arr[][3]={{1,2,3},{4,5,6},{7,8,9}};
    int n=3;
    int m=3;
    diagonalsum(arr,n,m);
}