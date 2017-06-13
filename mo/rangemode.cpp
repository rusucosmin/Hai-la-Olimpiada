#include <bits/stdc++.h>

using namespace std;

const int B = 316;
const int maxn = 100005;

int n, m, a[maxn], fr[maxn], ans[maxn];
struct classComp {
    bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) const {
        return lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second);
    }
};
struct classCompBucket {
    bool operator() (const pair<pair<int, int>, int> lhs, const pair<pair<int, int>, int> rhs) const {
        return lhs.first.first / B < rhs.first.first / B || (lhs.first.first / B == rhs.first.first / B
                && lhs.first.second < rhs.first.second);
    }
};

set<pair<int, int>, classComp> mset;
vector <pair<pair<int, int>, int>> mo;

inline void add(int x) {
    auto it = mset.find(make_pair(fr[x], x));
    if(it != mset.end())
        mset.erase(it);
    ++ fr[x];
    mset.insert(make_pair(fr[x], x));
}

inline void remove(int x) {
    auto it = mset.find(make_pair(fr[x], x));
    if(it != mset.end())
        mset.erase(it);
    -- fr[x];
    mset.insert(make_pair(fr[x], x));
}

inline int getSol() {
    assert(mset.size() != 0);
    auto it = mset.begin();
    return it->second;
}

int main() {
    ifstream fin("rangemode.in");
    ofstream fout("rangemode.out");

    fin >> n >> m;
    for(int i = 1; i <= n; ++ i)
        fin >> a[i];
    for(int i = 1; i <= m; ++ i) {
        int x, y;
        fin >> x >> y;
        mo.push_back(make_pair(make_pair(x, y), i));
    }
    sort(mo.begin(), mo.end(), classCompBucket());
    int l = 1, r = 1;
    ++ fr[a[1]];
    mset.insert(make_pair(fr[a[1]], a[1]));
    for(int i = 0; i < m ; ++ i) {
        int actl = mo[i].first.first;
        int actr = mo[i].first.second;
        int ind = mo[i].second;
        while(l < actl) {
            remove(a[l]);
            ++ l;
        }
        while(r < actr) {
            ++ r;
            add(a[r]);
        }
        while(actl < l) {
            -- l;
            add(a[l]);
        }
        while(actr < r) {
            remove(a[r]);
            -- r;
        }
        //cerr << "current at: " << l << ' ' << r << '\n';
        //for(auto it : mset)
        //    cerr << it.first << ' ' << it.second << '\n';
        ans[ind] = getSol();
    }
    for(int i = 1; i <= m; ++ i) {
        fout << ans[i] << '\n';
        //cout << ans[i] << ' ';
    }
}
