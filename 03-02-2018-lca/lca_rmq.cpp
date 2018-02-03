#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int maxn = 100005;
const int maxk = 20;

int n, m, dad[maxn], deep[maxn], euler[maxn * 2], K, euler_lvl[maxn * 2];
int rmq[maxk][2 * maxn], lg[2 * maxn], fst[maxn];
vector <int> g[maxn];

void dfs(int node) {
  euler[++ K] = node;
  euler_lvl[K] = deep[node];
  fst[node] = K;
  for(auto it : g[node]) {
    deep[it] = deep[node] + 1;
    dfs(it);
    euler[++ K] = node;
    euler_lvl[K] = deep[node];
  }
}

int lca(int x, int y) {
  x = fst[x];
  y = fst[y];
  if(x > y) {
    swap(x, y);
  }
  // x <= y
  int k = lg[y - x + 1];
  int ind1 = rmq[k][x]; // [x, x + 2^k - 1]
  int ind2 = rmq[k][y - (1 << k) + 1]; // [y - 2^k + 1,  y]
  // x + 2 ^ k - 1 - (y - 2^k + 1) =
  // x + 2 ^ k - 1 - y + 2^k - 1 =
  // x + 2 ^ k - 1 - y + 2^k - 1 =
  // -(y - x + 1) + 2 ^ (k + 1) - 1
  // - 2 ^ k + 2 ^ (k + 1) - 1
  // 2 ^ k - 1 >= 0 // k >= 1
  // k = [log2(y - x + 1)]
  // 2 ^ k ~= y - x + 1
  if(euler_lvl[ind1] < euler_lvl[ind2]) {
    return euler[ind1];
  } else {
    return euler[ind2];
  }
}

int main() {
  ifstream fin("lca.in");
  ofstream fout("lca.out");

  fin >> n >> m;
  for(int i = 2; i <= n; ++ i) {
    int x;
    fin >> x;
    g[x].push_back(i);
  }
  deep[1] = 1;
  dfs(1);
  // preprocesare rmq
  for(int i = 1; i <= K; ++ i) {
    rmq[0][i] = i; // retinem INDICI in rmq
  }
  for(int i = 2; i <= K; ++ i) {
    lg[i] = lg[i >> 1] + 1;
  }
  for(int k = 1; (1 << k) <= K; ++ k) {
    for(int i = 1; i + (1 << k) - 1 <= K; ++ i) {
      int ind1 = rmq[k - 1][i];
      int ind2 = rmq[k - 1][i + (1 << (k - 1))];
      if(euler_lvl[ind1] > euler_lvl[ind2]) {
        rmq[k][i] = ind2;
      } else {
        rmq[k][i] = ind1;
      }
    }
  }
  while(m --) {
    int x, y;
    fin >> x >> y;
    fout << lca(x, y) << '\n';
  }
  return 0;
}














