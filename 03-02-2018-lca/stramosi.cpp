#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int maxn = 250005;
const int maxk = 20;

int n, m, dad[maxn], deep[maxn], dp[maxk][maxn];

int stramos(int p, int q) {
  for(int bit = 0; (1 << bit) <= n; ++ bit) {
    if(p & (1 << bit)) {
      q = dp[bit][q];
    }
  }
  return q;
}

int main() {
  ifstream fin("stramosi.in");
  ofstream fout("stramosi.out");

  fin >> n >> m;
  for(int i = 1; i <= n; ++ i) {
    fin >> dp[0][i];
  }
  // 1 <= i <= log2(N) <=> 2 <= 2^i <= N
  for(int i = 1; (1 << i) <= n; ++ i) {
    for(int j = 1; j <= n; ++ j) {
      dp[i][j] = dp[i - 1][ dp[i - 1][j] ];
    }
  }
  while(m --) {
    int p, q;
    fin >> q >> p;
    fout << stramos(p, q) << '\n';
  }
  return 0;
}
