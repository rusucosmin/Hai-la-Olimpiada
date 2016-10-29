#include <iostream>
#include <fstream>

using namespace std;

int n, v[50];
ofstream fout("submultimi.out");

void bits() {
    for(int conf = 1; conf < (1 << n); ++ conf) {
        for(int i = 0; i < n; ++ i)
            if(conf & (1 << i))
                fout << (i + 1) << ' ';
        fout << '\n';
    }
}

void back(int p) {
    if(p == n + 1) {
        bool ok = false;
        for(int i = 1; i <= n; ++ i) {
            if(v[i] != 0)
                ok = true;
        }
        if(ok) {
            for(int i = 1; i <= n; ++ i)
                if(v[i])
                    fout << i << ' ';
            fout << '\n';
        }
        return ;
    }
    v[p] = 0;
    back(p + 1);
    v[p] = 1;
    back(p + 1);
}

int main() {
    ifstream fin("submultimi.in");

    fin >> n;
    back(1);
}
