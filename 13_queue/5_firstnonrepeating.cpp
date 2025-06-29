#include<iostream>
#include<string>
#include<queue>
using namespace std;

void FNRE(string str) {
    queue<char> q;
    int freq[26] = {0}; // for lowercase letters only

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        freq[ch - 'a']++;
        q.push(ch);

        // Remove characters from front that have freq > 1
        while (!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // Print stream so far
        for (int j = 0; j <= i; j++) {
            cout << str[j];
        }
        cout << "     ";

        // Print first non-repeating character
        if (!q.empty()) {
            cout << q.front();
        } else {
            cout << -1;
        }
        cout << endl;
    }
}

int main() {
    string str = "aabccxb";
    FNRE(str);
    return 0;
}
