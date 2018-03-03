#include <fstream>
#include <algorithm>
#include <set>
#include <vector>
#include <stack>
#include <bitset>

using namespace std;

const int maxn = 100005;

vector <int> g[maxn];
int n, m, level[maxn], lowLink[maxn];
stack <pair<int, int>> st;
bitset <maxn> viz;
vector <vector<int>> comp;

void getBcc(int node, int son) {
  int x, y;
  vector <int> s;
  do {
    x = st.top().first;
    y = st.top().second;
    st.pop();
    s.push_back(x);
    s.push_back(y);
  } while (node != x || son != y);
  sort(s.begin(), s.end());
  s.erase(unique(s.begin(), s.end()), s.end());
  comp.push_back(s);
}

void dfs(int node, int father) {
  viz[node] = 1;
  level[node] = level[father] + 1;
  lowLink[node] = level[node];
  for(auto it: g[node]) {
    if(!viz[it]) {
      // fiu in arbore df
      st.push(make_pair(node, it));
      dfs(it, node);
      lowLink[node] = min(lowLink[node], lowLink[it]);
      if(lowLink[it] >= level[node]) {
        getBcc(node, it);
      }
    } else if(it != father) {
      // muchie de 'intoarcere'
      lowLink[node] = min(lowLink[node], level[it]);
      //lowLink[node] = min(lowLink[node], lowLink[it]); - bug
    }
  }
}

int main() {
  ifstream fin("biconex.in");
  ofstream fout("biconex.out");

  fin >> n >> m;
  while (m --) {
    int x, y;
    fin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1, 0);

  fout << comp.size() << '\n';
  for (auto s : comp) {
    for (auto it : s) {
      fout << it << ' ';
    }
    fout << '\n';
  }
}
