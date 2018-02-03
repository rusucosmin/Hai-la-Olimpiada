#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int maxn = 100005;
const int maxk = 20;

int n, m, dad[maxn], deep[maxn], dp[maxk][maxn];
vector <int> g[maxn];

int stramos(int p, int q) {
  for(int bit = 0; bit < maxk; ++ bit) {
    if(p & (1 << bit)) {
      q = dp[bit][q];
    }
  }
  return q;
}

int lca(int x, int y) {
  if (deep[x] < deep[y]) {
    return lca(y, x);
  }
  // deep[x] > deep[y];
  x = stramos(deep[x] - deep[y], x);
  if(x == y) {
    return x;
  }
  for(int k = maxk - 1; k >= 0; -- k) { // O(log2(N))
    if(dp[k][x] != dp[k][y]) {
      x = dp[k][x];
      y = dp[k][y];
    }
  }
  return dp[0][x];
}

void dfs(int node) {
  for(auto it : g[node]) {
    deep[it] = deep[node] + 1;
    dfs(it);
  }
}

int main() {
  ifstream fin("lca.in");
  ofstream fout("lca.out");

  fin >> n >> m;
  for(int i = 2; i <= n; ++ i) {
    fin >> dp[0][i];
    g[dp[0][i]].push_back(i);
  }
  deep[1] = 1;
  dfs(1);
  for(int i = 1; i < maxk; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      dp[i][j] = dp[i - 1][ dp[i - 1][j] ];
    }
  }
  while(m --) {
    int x, y;
    fin >> x >> y;
    fout << lca(x, y) << '\n';
  }
  return 0;
}
