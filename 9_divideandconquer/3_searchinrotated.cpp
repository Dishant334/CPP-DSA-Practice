#include <iostream>
using namespace std;

int searchRotatedRecursive(int arr[], int si, int ei, int key) {
    if (si > ei)
        return -1; // Base case: not found

    int mid = si + (ei - si) / 2;

    if (arr[mid] == key)
        return mid;

    // Check if left half is sorted
    if (arr[si] <= arr[mid]) {
        if (key >= arr[si] && key < arr[mid])
            return searchRotatedRecursive(arr, si, mid - 1, key); // search in left
        else
            return searchRotatedRecursive(arr, mid + 1, ei, key); // search in right
    }

    // Right half is sorted
    else {
        if (key > arr[mid] && key <= arr[ei])
            return searchRotatedRecursive(arr, mid + 1, ei, key); // search in right
        else
            return searchRotatedRecursive(arr, si, mid - 1, key); // search in left
    }
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2, 3};
    int n = sizeof(arr) / sizeof(int);
    int key = 4;

    int result = searchRotatedRecursive(arr, 0, n - 1, key);
    if (result != -1)
        cout << "Key is found at index " << result << endl;
    else
        cout << "Key not found" << endl;
}
