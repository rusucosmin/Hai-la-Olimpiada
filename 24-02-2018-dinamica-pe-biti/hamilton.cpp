#include <iostream>
#include <fstream>
#include <vector>
#include <memory.h>

using namespace std;

const int maxn = 18;
const int inf = 0x3f3f3f3f;

vector <pair<int, int>> g[maxn], gt[maxn];
int n, m, dp[1 << maxn][maxn];

int main() {
  ifstream fin("hamilton.in");
  ofstream fout("hamilton.out");

  fin >> n >> m;

  for(int i = 0; i < m; ++ i) {
    int x, y, z;
    fin >> x >> y >> z;
    g[x].push_back(make_pair(y, z));
    gt[y].push_back(make_pair(x, z));
  }

  memset(dp, inf, sizeof(dp));

  // conf
  dp[1][0] = 0;

  /*

  dinamica inpoi
  for(int conf = 2; conf < (1 << n); ++ conf) {
    for(int i = 0; i < n; ++ i) {
      if(conf & (1 << i)) {
        for(auto e : gt[i]) {
          if(conf & (1 << e.first)) {
            dp[conf][i] = min(dp[conf][i],
                dp[conf ^ (1 << i)][e.first] + e.second);
          }
        }
      }
    }
  }
  */
  // dinamica inainte
  for(int conf = 1; conf < (1 << n); ++ conf) {
    for(int i = 0; i < n; ++ i) {
      if(conf & (1 << i)) {
        for(auto e : g[i]) {
          if(!(conf & (1 << e.first))) {
            dp[conf | (1 << e.first)][e.first] =
                min(dp[conf | (1 << e.first)][e.first],
                    dp[conf][i] + e.second);
          }
        }
      }
    }
  }

  int sol = inf;

  // (conf, i)

  for(auto e : gt[0]) {
    sol = min(sol, dp[(1 << n) - 1][e.first] + e.second);
  }

  if (sol == inf) {
    fout << "Nu exista solutie\n";
  } else {
    fout << sol << '\n';
  }
}




























