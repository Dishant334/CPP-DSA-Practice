#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
   return p1.second>p2.second;
}

void JobSequence(vector<int>deadline,vector<int>profit,int n){
    vector<pair<int,int>>Seq(n,make_pair(0,0));

    for(int i=0;i<n;i++){
        Seq[i]=make_pair(deadline[i],profit[i]);
    }
    sort(Seq.begin(),Seq.end(),compare);
int currdeadline=Seq[0].first;
int currprofit=Seq[0].second;
for(int i=0;i<n;i++){
    if(Seq[i].first>currdeadline){
        currprofit += Seq[i].second;
        currdeadline=Seq[i].first;
    }
}
cout<<currprofit;
}
int main(){
    vector<int>deadline={4,1,1,1};
    vector<int>profit={20,10,40,30};
    JobSequence(deadline,profit,deadline.size());
}