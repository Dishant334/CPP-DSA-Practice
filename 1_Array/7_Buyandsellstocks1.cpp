#include<iostream>
using namespace std;
void bestbuy(int arr[],int n){
    int i,j;
    int maxprofit=0;
     int bestBuy=INT16_MAX;
     int bestBuyidx=-1;
     int bestSell=INT16_MIN;
     for(i=0;i<n;i++){
        if(bestBuy>arr[i]){
            bestBuy=arr[i];
            bestBuyidx=i; 
        }
    }
     if(bestBuy==arr[n-1]){
        cout<<0;
        return;
     }
     for(j=bestBuyidx+1;j<n;j++){
        bestSell=max(bestSell,arr[j]);
     }
     maxprofit=bestSell-bestBuy;
     cout<<"best sell at "<<bestSell<<endl;
     cout<<"best buy at "<<bestBuy<<" at the day "<<bestBuyidx<<endl;;
     cout<<maxprofit;
}
int main(){
    int arr[]={7,54,5,3,6,1};
    int n=sizeof(arr)/sizeof(int);
    bestbuy(arr,n);
}