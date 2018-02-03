#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int maxn = 100005;

int n, m, dad[maxn], deep[maxn];
vector <int> g[maxn];

void dfs(int node) {
  for(auto it : g[node]) {
    deep[it] = deep[node] + 1;
    dfs(it);
  }
}

int lca(int x, int y) {
  while(deep[x] > deep[y]) {
    x = dad[x];
  }
  while(deep[y] > deep[x]) {
    y = dad[y];
  }
  while(x != y) {
    x = dad[x];
    y = dad[y];
  }
  return x;
}

int main() {
  ifstream fin("lca.in");
  ofstream fout("lca.out");

  fin >> n >> m;
  for(int i = 2; i <= n; ++ i) {
    fin >> dad[i];
    g[dad[i]].push_back(i);
  }
  deep[1] = 1;
  dfs(1);
  while(m --) {
    int x, y;
    fin >> x >> y;
    fout << lca(x, y) << '\n';
  }
  return 0;
}
