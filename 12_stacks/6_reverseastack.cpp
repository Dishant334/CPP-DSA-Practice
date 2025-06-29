#include<iostream>
#include<stack>
using namespace std;

void print(stack<int> s) { // Make a copy to preserve original
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void pAB(stack<int>& s, int value) {
    if (s.empty()) {
        s.push(value);
        return;
    }
    int temp = s.top();
    s.pop();
    pAB(s, value);
    s.push(temp);
}

void reverse(stack<int>& s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    reverse(s);
    pAB(s, temp);
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Original stack: ";
    print(s);

    reverse(s);

    cout << "Reversed stack: ";
    print(s);

    return 0;
}

