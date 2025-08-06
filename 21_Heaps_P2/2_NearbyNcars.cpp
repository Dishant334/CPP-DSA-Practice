#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// Function to compute square of distance from origin
int distance(int x, int y) {
    return x * x + y * y; // No need to take sqrt
}

vector<pair<int, int>> kClosestCars(vector<pair<int, int>>& cars, int k) {
    // Max heap: stores pair {distance, {x, y}}
    priority_queue<pair<int, pair<int, int>>> pq;

    for (int i = 0; i < cars.size(); i++) {
        int x = cars[i].first;
        int y = cars[i].second;
        int dist = distance(x, y);
        pq.push({dist, {x, y}});

        // Maintain heap size of at most k
        if (pq.size() > k)
            pq.pop();
    }

    // Extract k closest cars
    vector<pair<int, int>> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    return result;
}

int main() {
    vector<pair<int, int>> cars = {{1, 2}, {2, 3}, {3, 4}, {0, 1}, {5, 1}};
    int k = 2;

    vector<pair<int, int>> closest = kClosestCars(cars, k);

    cout << k << " nearest cars to origin are:\n";
    for (int i = 0; i < closest.size(); i++) {
        cout << "(" << closest[i].first << ", " << closest[i].second << ")\n";
    }

    return 0;
}
