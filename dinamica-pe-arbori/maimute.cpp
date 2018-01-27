#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

using namespace std;

const int maxn = 100005;

int n, first[maxn], last[maxn], K;
vector <int> g[maxn];
bitset <maxn> vis;

void dfs(int node) {
  vis[node] = 1;
  first[node] = ++ K;
  for(auto fiu : g[node]) {
    if(!vis[fiu]) {
      dfs(fiu);
    }
  }
  last[node] = ++ K;
}

int main() {
  ifstream fin("maimute.in");
  ofstream fout("maimute.out");

  fin >> n;

  for(int i = 1; i < n; ++ i) {
    int x, y;
    fin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1);

  /*for(int i = 1; i <= n; ++ i) {
    cout << i << ' ';
    cout << first[i] << ' ' << last[i] << '\n';
  }*/

  int q;

  fin >> q;
  for(int i = 0; i < q; ++ i) {
    int x, y;
    fin >> x >> y;
    if((first[x] < first[y] && last[y] < last[x])
        || (first[y] < first[x] && last[x] < last[y])) {
          fout << "DA\n";
    } else {
      fout << "NU\n";
    }
  }
}

