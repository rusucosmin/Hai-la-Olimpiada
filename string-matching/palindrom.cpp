#include <fstream>
#include <vector>
#include <bitset>
#include <string.h>
 
using namespace std;
 
const char infile[] = "palindrom.in";
const char outfile[] = "palindrom.out";
 
ifstream fin(infile);
ofstream fout(outfile);
 
const int MAXN = 200005;
const int BASE = 33;
const int oo = 0x3f3f3f3f;
 
typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;
 
const inline int min(const int &a, const int &b) { if( a > b ) return b;   return a; }
const inline int max(const int &a, const int &b) { if( a < b ) return b;   return a; }
const inline void Get_min(int &a, const int b)    { if( a > b ) a = b; }
const inline void Get_max(int &a, const int b)    { if( a < b ) a = b; }
 
char text[MAXN];
 
int main() {
    fin.getline(text, MAXN);
    int N = strlen(text);
    int Ans = N;
    long long Hash = 0, invHash = 0, BIG = 1;
    for(int i = N - 1 ; i >= 0 ; -- i) {
        Hash = Hash * BASE + (text[i] - 'a');
        invHash = (text[i] - 'a') * 1LL * BIG + invHash;
        if(Hash == invHash)
            Ans = i;
        BIG = BIG * BASE;
    }
    fout << text;
    for(int i = Ans - 1 ; i >= 0 ; -- i)
        fout << text[i];
    fin.close();
    fout.close();
    return 0;
}
