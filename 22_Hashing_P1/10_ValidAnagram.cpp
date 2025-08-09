#include<iostream>
#include<unordered_map>

using namespace std;

bool Anagram(string str1,string str2){
    unordered_map<char,int>m;    //we will store every char of str1 as key and freq of each el as value and then decrease freq of each till it become 0 for each
    if(str1.size()!=str2.size()){
        return false;
    }
    for(int i=0;i<str1.size();i++){    
        if(m.count(str1[i])==1){
          m[str1[i]]++;
        }else{
            m[str1[i]]=1;
        }
    }

    for(int i=0;i<str2.size();i++){
         if(m.count(str2[i])){
            m[str2[i]]--;

            if(m[str2[i]]==0){
                m.erase(str2[i]);
            }
         }else{
            return false;
         }
    }

    if(m.size()==0){
        return true;
    }
    return false;
}
int main(){
    string str1="race";
    string str2="care";

   cout<< Anagram(str1,str2);
}