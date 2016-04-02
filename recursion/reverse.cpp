#include <iostream>

using namespace std;

void afisare() {
    char ch;
    cin.get(ch);
    if(ch != '\n')
        afisare();
    cout << ch;
}

int fibo(int n) {
    if(Fibonacci[n] != 0)
        return Fibonacci[n];
    if(n == 1 || n == 2)
        Fibonacci[n] = 1;
    else
        Fibonacci[n] = fibo(n - 1) + fibo(n - 2);
    return Fibonacci[n];
}

int main() {
    afisare();
    return 0;
}
