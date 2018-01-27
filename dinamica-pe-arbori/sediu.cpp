#include <iostream>
#include <fstream>
#include <bitset>
#include <vector>

using namespace std;

const int maxn = 16005;

vector <int> g[maxn];

bitset <maxn> viz;

int n, subarb[maxn], dp[maxn];

// dp[i] = max(subarb[fiu], N - subarb[i]);

void dfs(int node) {
  viz[node] = 1;
  subarb[node] = 1; // exista cel putin nodul node
  dp[node] = 0;
  for(auto fiu : g[node]) {
    if(!viz[fiu]) {
      dfs(fiu);
      subarb[node] += subarb[fiu];
      dp[node] = max(dp[node], subarb[fiu]);
    }
  }
  dp[node] = max(dp[node], n - subarb[node]);
}

int main() {
  ifstream fin("sediu.in");
  ofstream fout("sediu.out");

  fin >> n;

  for(int i = 1; i < n; ++ i) {
    int x, y;
    fin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1);

  int O = 0x3f3f3f3f;
  for(int i = 1; i <= n; ++ i) {
    O = min(O, dp[i]);
  }
  fout << O << ' ';
  vector <int> sedii;
  for(int i = 1; i <= n; ++ i) {
    if(dp[i] == O) {
      sedii.push_back(i);
    }
  }
  fout << sedii.size() << '\n';
  for(auto it : sedii) {
    fout << it << ' ';
  }
}

