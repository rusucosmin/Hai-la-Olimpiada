#include <iostream>
#include <fstream>

using namespace std;

const int maxlg = 20;
const int maxn = 100005;

int rmq[maxlg][maxn], lg[maxn], n, m;

int main() {
    ifstream fin("rmq.in");
    ofstream fout("rmq.out");

    fin >> n >> m;
    for(int i = 2; i <= n; ++ i)
        lg[i] = lg[i / 2] + 1;
    for(int i = 1; i <= n; ++ i)
        fin >> rmq[0][i];
    for(int k = 1; (1 << k) <= n; ++ k)
        for(int i = 1; i <= n; ++ i)
            rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
    for(int i = 1; i <= m; ++ i) {
        int x, y;
        fin >> x >> y;
        int l = lg[y - x + 1];
        int ans = rmq[l][x];
        if(rmq[l][y - (1 << l) + 1] < ans)
            ans = rmq[l][y - (1 << l) + 1];
        fout << ans << '\n';
    }


    /*
    *
    *
    */

}
