#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(!b)
        return a;
    if(!a)
        return b;
    return gcd(a, a % b);
}

int main() {
    cout << gcd(25, 10) << '\n';
    /// gcd(10, 25) = gcd(5, 25)
    return 0;
}
