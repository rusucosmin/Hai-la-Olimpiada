#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <stack>
#include <deque>
#include <iomanip>
#include <set>
#include <map>
#include <cassert>
#include <ctime>
#include <list>
#include <iomanip>

using namespace std;

string file = "prefix";

ifstream cin( (file + ".in").c_str() );
ofstream cout( (file + ".out").c_str() );

const int MAXN = 1000005;
const int oo = (1<<31)-1;

char A[MAXN];
int Prefix[MAXN];

inline int Solve() {
    int N, K = 0;
    memset(Prefix, 0, sizeof(Prefix));
    cin >> (A+1);
    N = strlen(A+1);
    Prefix[1] = 0;
    for(int i = 2 ; i <= N ; ++ i) {
        while( K > 0 && A[K + 1] != A[i])
            K = Prefix[K];
        if(A[K+1] == A[i])
            ++ K;
        Prefix[i] = K;
    }
    for(int i = N ; i >= 2 ; -- i)
        if(Prefix[i] && !(i % (i - Prefix[i])))
            return i;
    return 0;
}

int main() {
    int T;
    for(cin >> T ; T ; -- T) {
        cout << Solve() << '\n';
    }
    cin.close();
    cout.close();
    return 0;
}
