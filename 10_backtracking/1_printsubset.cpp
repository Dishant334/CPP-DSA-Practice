#include <iostream>
#include <string>
using namespace std;

void Subset(string str, string substr) {
    if (str.empty()) {
        cout << substr << " ";
        return;
    }

    char ch = str[0];
    string rest = str.substr(1); // Safe because str is not empty here

    // Include the character
    Subset(rest, substr + ch);

    // Exclude the character
    Subset(rest, substr);
}

int main() {
    string str = "Apple";
    Subset(str, "");
    return 0;
}

