#include <iostream>
#include <fstream>

using namespace std;

const int maxn = 1005;

int a[maxn][maxn];

int nr_cel;
int n, m, xst, yst;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = { 0,-1, 0, 1};

inline bool inside(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void fill(int x, int y, int act) {
    a[x][y] = act;
    ++ nr_cel;
    for(int d = 0; d < 4; ++ d) {
        int newx = x + dx[d];
        int newy = y + dy[d];
        if(inside(newx, newy) && a[newx][newy] == 0)
            fill(newx, newy, act);
    }
}

int main() {
    ifstream fin("fill.in");
    ofstream fout("fill.out");

    fin >> n >> m;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            fin >> a[i][j];
    int nr_insule = 1;
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= m; ++ j)
            if(a[i][j] == 0) {
                ++ nr_insule;
                fill(i, j, nr_insule);
            }
    for(int i = 1; i <= n; ++ i, cout << '\n')
        for(int j = 1; j <= m; ++ j)
            cout << a[i][j] << ' ';
    return 0;
}
