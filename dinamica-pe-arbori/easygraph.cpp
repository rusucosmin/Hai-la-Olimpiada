#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

using namespace std;

const int maxn = 15005;

int t, n, m, v[maxn];
long long dp[maxn];
long long sol = -100005;
vector <int> g[maxn];
bitset <maxn> used;

inline void dfs(int node) {
  if(used[node])
    return ;
  used[node] = 1;
  dp[node] = v[node];
  for(auto fiu : g[node]) {
    dfs(fiu);
    dp[node] = max(dp[node], v[node] + dp[fiu]);
  }
  sol = max(sol, dp[node]);
}

int main() {
  ifstream fin("easygraph.in");
  ofstream fout("easygraph.out");
  fin >> t;
  while(t --) {
    fin >> n >> m;
    for(int i = 1; i <= n; ++ i) {
      fin >> v[i];
    }
    for(int i = 0; i < m; ++ i) {
      int x, y;
      fin >> x >> y;
      g[x].push_back(y);
    }
    for(int i = 1; i <= n; ++ i) {
      if(!used[i]) {
        dfs(i);
      }
    }
    fout << sol << '\n';
    for(int i = 1; i <= n; ++ i) {
      g[i].clear();
    }
    sol = -100005;
    used.reset();
  }
  return 0;
}

