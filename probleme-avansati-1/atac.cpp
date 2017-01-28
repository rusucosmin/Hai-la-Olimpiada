#include <bits/stdc++.h>

using namespace std;

ifstream fin("atac.in");
ofstream fout("atac.out");
int n,m,p;
const int NMAX = 32005;
const int MAXLOG = 18;
int dp[MAXLOG][NMAX];
int anc[MAXLOG][NMAX];
int level[NMAX];
vector <pair<int, int> > g[NMAX];

void dfs(int node, int dad) {
    for(auto it : g[node]) {
        if(it.first == dad)
            continue;
        level[it.first] = level[node] + 1;
        anc[0][it.first] = node;
        dp[0][it.first] = it.second;
        dfs(it.first, node);
    }
}

void citire()
{
    fin >> n >> m >> p;
    level[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        int x, y;
        fin >> x >> y;
        g[x].push_back(make_pair(i, y));
        g[i].push_back(make_pair(x, y));
    }
    dfs(1, 0);
}

void build ()
{
   int k,x;
   for (k=1;k<MAXLOG;k++)
     for (x=1;x<=n;x++)
      anc[k][x]=anc[k-1][anc[k-1][x]];
}

int solve(int x, int y) {
        if(level[x]<level[y]) swap(x,y);
    int diff = level[x]-level[y];
    int minim = 0x3f3f3f3f;
    for(int bit = 0; bit < MAXLOG; ++ bit) {
        if(diff & (1 << bit)) {
            minim = min(minim, dp[bit][x]);
            x = anc[bit][x];
        }
    }
    /// sunt la acelasi nivel
      for(int k = MAXLOG - 1; k >= 0; -- k) {
        if(anc[k][x] != anc[k][y]) {
            minim = min(minim, dp[k][x]);
          x = anc[k][x];
            minim = min(minim, dp[k][y]);
          y = anc[k][y];
        }
      }
      minim = min(minim, dp[0][x]);
      minim = min(minim, dp[0][y]);
      return minim;
}

void calculate_dynamics ()
{
  int k,x;
   for (k=1;k<MAXLOG;k++)
     for (x=1;x<=n;x++)
      dp[k][x]=min(dp[k-1][x],dp[k-1][anc[k-1][x]]);
}  
  
void queries() {
  int x,y,a,b,c,d,xaux,yaux;
    fin>>x>>y>>a>>b>>c>>d;
  for(int i=1;i<=m;++i) {
    int z=solve(x,y);
    if(i>=m-p+1) fout<<z<<'\n';
    xaux=(x*a+y*b)%n+1;
    yaux=(y*c+z*d)%n+1;
    x=xaux;
    y=yaux;
  }
}
int main()
{
  citire();
  build();
  calculate_dynamics();
  queries();
}
