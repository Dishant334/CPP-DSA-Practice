#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first > p2.first;  //desc
}

void Knapsack(vector<int>weight,vector<int>value,int W){
    //sort on basis of  ratio
    double ans=0.0;
    int n=value.size();
vector<pair<double,int>>ratio(n,make_pair(0.0,0));
for(int i=0;i<weight.size();i++){
    double r=value[i]/(double)weight[i];
    ratio[i]=make_pair(r,i);
}
sort(ratio.begin(),ratio.end(),compare);


for(int i=0;i<weight.size();i++){
    int idx=ratio[i].second;
    if(weight[idx]<=W){
        ans+=value[idx];
        W-=weight[idx];
    }
    else{
        ans+=ratio[i].first * W;
        W=0;
        break;
    }
}
    cout<<"the max value is = "<<ans<<endl;
}
int main(){
vector<int>value ={60,100,120};
vector<int>weight={10,20,30};
int W=50;
Knapsack(weight,value,W);
}