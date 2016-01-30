#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <utility>
#include <string.h>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <search.h>
#include <bitset>
 
#define s 0
using namespace std;
 
ifstream cin("johnie.in");
ofstream cout("johnie.out");
 
const int MAXN = 50005;
const int oo = (1<<31)-1;
 
typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;
 
vector<int> EulerComp;
Graph G;
int N, M;
stack <int> Stack;
bitset <MAXN> used;
 
inline void Euler(int st){
    for(Stack.push(st) ; !Stack.empty() ; ){
        int x = Stack.top();
        if(G[x].size()){
            int y = G[x].back();
            Stack.push(y);
            G[x].pop_back();
            G[y].erase(find(G[y].begin(), G[y].end() , x));
        }
        else{
            Stack.pop();
			used[x] = 1;
            if(x)
                EulerComp.push_back(x);
            else if(EulerComp.size()){
                cout << EulerComp.size() << " ";
                for(vector<int> :: iterator it = EulerComp.begin(), fin = EulerComp.end() ; it != fin ; ++ it)
                    cout << *it << " ";
                cout << "\n";
                EulerComp.clear();
            }
        }
    }
}
 
int main()
{
    int Odd = 0;
    cin >> N >> M;
    for(int i = 1 ; i <= M ; ++ i){
        int x, y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 1 ; i <= N ; ++ i)
        if(G[i].size() & 1){
            Odd ++;
            G[i].push_back(s);
            G[s].push_back(i);
        }
    cout << Odd/2 << "\n";
    Euler(0);
    cin.close();
    cout.close();
    return 0;
}
