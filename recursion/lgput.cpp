#include <iostream>
#include <fstream>

using namespace std;

const int mod = 1999999973;

ifstream fin("lgput.in");
ofstream fout("lgput.out");

int lgpow(int a, int n) {
    if(n == 0)
        return 1;
    int semipow = lgpow(a, n / 2);
    semipow = ((long long)semipow * semipow) % mod;
    if(n % 2 == 0)
        return semipow;
    else
        return ((long long)semipow * a) % mod;
}

int main() {
    int N, P;
    fin >> N >> P;
    fout << lgpow(N, P) << '\n';
}
