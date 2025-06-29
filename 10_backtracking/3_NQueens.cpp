#include<iostream>
#include<vector>
using namespace std;

void Nqueen(vector<char>board,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< " . ";
        }
        cout<<endl;
    }


}
int main(){
    vector<char>board;
    Nqueen(board,3);

}