#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestSubarray(vector<int> arr) {
    unordered_map<int,int> m;  
    m[0] = -1;  // sum 0 at index -1

    int sum = 0;
    int ans = 0;

    for(int j = 0; j < arr.size(); j++) {
        sum += arr[j];

        if(m.count(sum)) {
            int currLen = j - m[sum];  
            ans = max(ans, currLen);
        } else {
            m[sum] = j;  // store first occurrence
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};
    cout << "largest subarray with sum 0: " << largestSubarray(arr) << endl;
}
