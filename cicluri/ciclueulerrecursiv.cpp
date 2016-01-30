#include <iostream>
#include <fstream>
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
#define LE 500666
int result[LE],grad[LE];
bool viz[LE];
#include <vector>
vector<pair<int,int> > H[LE];
#define x first
#define y second
int K;
  
void dfs(int nod) {
    int N=H[nod].size();
    int i;
  
    for(i=0; i<N; ++i)
        if (viz[H[nod][i].y]==false) {
            viz[H[nod][i].y]=true;
            dfs(H[nod][i].x);
        //  break;
        }
    result[++K]=nod;
}
#define mp make_pair
#define pb push_back
int main() {
    int n,m,xx,yy,i;
  
    f>>n>>m;
    for(i=1; i<=m; ++i) {
        f>>xx>>yy;
        H[xx].pb(mp(yy,i));
        H[yy].pb(mp(xx,i));
        grad[xx]++;
        grad[yy]++;
    }
  
    for(i=1; i<=n; ++i) if (grad[i]%2) {
            g<<-1;
            return 0 ;
        }
    dfs(1);
  
    for(i=1; i<K; ++i)
        g<<result[i]<<" ";
  
    f.close();
    g.close();
    return 0;
}
