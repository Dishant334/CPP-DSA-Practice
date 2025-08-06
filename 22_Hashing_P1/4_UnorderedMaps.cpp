#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<string,int>m;

    m["China"]=150;
    m["India"]=150;
    m["US"]=50;
    m["Nepal"]=10;

    for(pair<string,int> country : m){
        cout<<country.first <<","<<country.second<<endl;
    }
}