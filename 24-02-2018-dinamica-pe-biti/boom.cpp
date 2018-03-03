#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

const int maxn = 20;
const int maxm = 50;
const int inf = 0x3f3f3f3f;

int n, m;
int cost[maxm], mask[maxm];
int dist[1 << maxn];
pair<int, int> dad[1 << maxn];

int main() {
  ifstream fin("boom.in");
  ofstream fout("boom.out");

  fin >> n >> m;
  for(int i = 0; i < m; ++ i) {
    fin >> cost[i];
    int x;
    fin >> x;
    for (int j = 0; j < x; ++ j) {
      int y;
      fin >> y;
      mask[i] |= (1 << (y - 1));
    }
  }

  memset(dist, inf, sizeof(dist));
  priority_queue <pair<int, int>, vector <pair<int, int>>,
      greater<pair<int, int>>> q;
  dist[0] = 0;
  q.push(make_pair(dist[0], 0));

  while(!q.empty()) {
    int act = q.top().first;
    int node = q.top().second;
    q.pop();
    if(node == (1 << n) - 1) {
      break;
    }
    for(int i = 0; i < m; ++ i) {
      int step1 = node | mask[i];
      int newNode = ((step1 >> 1) | (1 << (n - 1))) & ((step1 << 1) | 1);
      if (dist[newNode] > dist[node] + cost[i]) {
        dist[newNode] = dist[node] + cost[i];
        dad[newNode] = make_pair(node, i + 1);
        q.push(make_pair(dist[newNode], newNode));
      }
    }
  }

  int node = (1 << n) - 1;
  fout << dist[node] << '\n';
  vector <int> ans;

  while(node != 0) {
    pair<int, int> now = dad[node];
    ans.push_back(now.second);
    node = now.first;
  }

  fout << ans.size() << '\n';
  for(auto it = ans.rbegin(); it != ans.rend(); ++ it) {
    fout << *it << '\n';
  }
}

























