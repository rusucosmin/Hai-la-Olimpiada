#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

inline bool cmp(char a, char b) {
    return a > b;
}

int main() {
    string s = "ana are mere";
    for(auto it : s) {
        cout << (char)toupper(it);
    }
    cout << '\n';
    for(int i = 0; i < (int)s.size(); ++ i)
        cout << s[i];
    cout << '\n';
    for(int i = s.size() - 1; i >= 0; -- i)
        cout << s[i];
    cout << '\n';
    for(auto it = s.rbegin(); it != s.rend(); ++ it)
        cout << *it;
    return 0;
}
