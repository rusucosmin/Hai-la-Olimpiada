#include <iostream>
#include <fstream>

using namespace std;

const int maxn = 100005;
const int maxk = 20;

int n, m, rmq[maxk][maxn], lg[maxn];

int RMQ(int x, int y) {
  if(x > y) {
    swap(x, y);
  }
  int k = lg[y - x + 1];
  int sol = rmq[k][x];
  if(rmq[k][y - (1 << k) + 1] < sol) {
    sol = rmq[k][y - (1 << k) + 1];
  }
  return sol;
}

int main() {
  ifstream fin("rmq.in");
  ofstream fout("rmq.out");

  fin >> n >> m;
  for(int i = 1; i <= n; ++ i) {
    fin >> rmq[0][i];
  }
  for(int i = 2; i <= n; ++ i) {
    lg[i] = lg[i >> 1] + 1;
  }
  for(int k = 1; (1 << k) <= n; ++ k) {
    for(int i = 1; i + (1 << k) - 1 <= n; ++ i) {
      rmq[k][i] = min(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
    }
  }
  while(m --) {
    int x, y;
    fin >> x >> y;
    fout << RMQ(x, y) << '\n';
  }
}
