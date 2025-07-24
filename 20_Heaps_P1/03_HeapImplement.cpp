#include<iostream>
#include<vector>
using namespace std;

class Heap {
    vector<int> vec;

public:
    void push(int val) {
        vec.push_back(val);
        int x = vec.size() - 1;
        int parIdx = (x - 1) / 2;

        while (x > 0 && vec[x] > vec[parIdx]) {
            swap(vec[x], vec[parIdx]);
            x = parIdx;
            parIdx = (x - 1) / 2;
        }
    }

    void heapify(int idx) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < vec.size() && vec[left] > vec[largest]) {
            largest = left;
        }
        if (right < vec.size() && vec[right] > vec[largest]) {
            largest = right;
        }

        if (largest != idx) {
            swap(vec[idx], vec[largest]);
            heapify(largest);
        }
    }

    void pop() {
        if (vec.empty()) return;

        swap(vec[0], vec[vec.size() - 1]);
        vec.pop_back();
        heapify(0);
    }

    int top() {
        if (!vec.empty()) return vec[0];
    }

    bool empty() {
        return vec.empty();
    }

    void print() {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(5);
    heap.push(20); 

    cout << "Heap top: " << heap.top() << endl;
    heap.print();

    heap.pop();
    cout << "After pop:" << endl;
    cout << "Heap top: " << heap.top() << endl;
    heap.print();
}
