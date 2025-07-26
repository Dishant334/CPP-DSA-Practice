#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct ComparePair{
    bool operator () (pair<string,int> &p1,pair<string,int>&p2){
         return p1.second < p2.second;
    }
};

int main(){
    priority_queue<pair<string,int>,vector<pair<string,int>>,ComparePair>pq;

    pq.push(make_pair("bhumika",98));
    pq.push(make_pair("aman",20));
    pq.push(make_pair("zeeshan",50));

    while(!pq.empty()){
        cout<<"top ="<<pq.top().first<<" , "<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}
//on the basis of first it would print but if you want to do it for second then
//we can make custom comarator or custom class