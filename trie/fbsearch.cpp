#include <fstream>
#include <vector>
#include <bitset>
#include <string.h>
#include <map>
#include <string>
#include <cassert>
 
using namespace std;
 
const char infile[] = "fbsearch.in";
const char outfile[] = "fbsearch.out";
 
ifstream fin(infile);
ofstream fout(outfile);
 
const int MAXN = 100005;
const int SIGMA = 26;
const int oo = 0x3f3f3f3f;
 
typedef vector<int> Graph[MAXN];
typedef vector<int> :: iterator It;
 
const inline int min(const int &a, const int &b) { if( a > b ) return b;   return a; }
const inline int max(const int &a, const int &b) { if( a < b ) return b;   return a; }
const inline void Get_min(int &a, const int b)    { if( a > b ) a = b; }
const inline void Get_max(int &a, const int b)    { if( a < b ) a = b; }
 
struct Trie {
    int best;
    Trie *Sons[SIGMA];
    Trie() {
        best = 0;
        memset(Sons, 0, sizeof(Sons));
    }
};
 
map <string, int> inde;
map <int, string> name;
 
int T, N, M, relevance[MAXN];
 
inline int getIndex(const char c) {
    if('a' <= c && c <= 'z')
        return  c - 'a';
    if('A' <= c && c <= 'Z')
        return c - 'A';
    return -1;
}
 
void Insert(Trie *Node, const string s, const int pos, const int sz, const int ind) {
    if(pos >= sz) {
        if(!Node -> best || (relevance[Node -> best] < relevance[ind] ||
                             (relevance[Node -> best] == relevance[ind] && name[Node -> best] > s)))
            Node -> best = ind;
        return;
    }
    if(!Node -> best || (relevance[Node -> best] < relevance[ind] ||
                     (relevance[Node -> best] == relevance[ind] && name[Node -> best] > s)))
        Node -> best = ind;
    int ch = getIndex(s[pos]);
    if(ch == -1) {
        //assert(false);
        return;
    }
    if(!Node -> Sons[ch])
        Node -> Sons[ch] = new Trie();
    Insert(Node -> Sons[ch], s, pos + 1, sz, ind);
}
 
string Query(Trie *Node, const string s, const int pos, const int sz) {
    if(pos == sz) {
        if(!Node -> best)
            return "Search Bing for " + s;
        return name[Node -> best];
    }
    int ch = getIndex(s[pos]);
    if(ch == -1 || !Node -> Sons[ch]) {
        //assert(false);
        return "Search Bing for " + s;
    }
    return Query(Node -> Sons[ch], s, pos + 1, sz);
}
 
int main() {
    fin >> T;
    for(int test = 1 ; test <= T ; ++ test) {
        Trie *Root = new Trie();
        fin >> N >> M;
        memset(relevance, 0, sizeof(relevance));
        inde.clear();
        name.clear();
        string s;
        for(int i = 1 ; i <= N ; ++ i) {
            fin >> s;
            inde[s] = i;
            name[i] = s;
            Insert(Root, s, 0, s.size(), i);
        }
        for(int i = 1 ; i <= M ; ++ i) {
            char ch;
            int nr;
            fin >> ch;
            if(ch == 'Q') {
                fin >> s;
                fout << Query(Root, s, 0, s.size()) << '\n';
            }
            else if(ch == 'U') {
                fin >> s;
                fin >> nr;
                relevance[inde[s]] += nr;
                Insert(Root, s, 0, s.size(), inde[s]);
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}
