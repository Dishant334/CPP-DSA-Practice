


#include<iostream>
#include <string>
using namespace std;


void anagram(string str1,string str2){
    int freq[26]={0};
    if(str1.length() !=str2.length()){
        cout<<"not a valid anagram"<<endl;
        return;
    }
    for(int i=0;i<str1.length();i++){
         freq[str1[i]-'a']++;       
    }

    for(int j=0;j<str2.length();j++){
        if(freq[str2[j]-'a']==0){
            cout<<"not a valid anagram"<<endl;
            return;
        }
    freq[str2[j]-'a']--;
    }
cout<<"it is a valid anagram"<<endl;
}
int main(){
    string str1="ram";
    string str2="cat";
anagram(str1,str2);
}