#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void SlidingWindowMax(vector<int> vec, int k) {
    vector<int> ans;

    // max-heap: stores {value, index}
    priority_queue<pair<int, int>> pq;

    for(int i = 0; i < vec.size(); i++) {
        // Push current element with its index
        pq.push({vec[i], i});

        // Remove elements whose index is out of the window
        while(!pq.empty() && pq.top().second <= i - k) {
            pq.pop();
        }

        // Store result once the first window is complete
        if(i >= k - 1) {
            ans.push_back(pq.top().first);
        }
    }

    // Print result
    for(int val : ans) {
        cout << val << " ";
    }
}

int main() {
    vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    SlidingWindowMax(vec, k);
    return 0;
}
