#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int maxn = 16005;

int n, v[maxn], dp[maxn];
vector <int> g[maxn];

void dfs(int node, int father) {
    dp[node] = v[node];
    for(auto it : g[node]) {
        if(it == father)
            continue;
        dfs(it, node);
        dp[node] = max(dp[node], dp[node] + dp[it]);
    }
}

int main() {
    ifstream fin("asmax.in");
    ofstream fout("asmax.out");

    fin >> n;
    for(int i = 1; i <= n; ++ i) {
        fin >> v[i];
    }
    for(int i = 1; i != n; ++ i) {
        int x, y;
        fin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0);
    int sol = dp[1];
    for(int i = 2; i <= n; ++ i)
        sol = max(sol, dp[i]);
    fout << sol << '\n';
}
