



#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

ifstream fin("damesah.in");
ofstream fout("damesah.out");

const int maxn = 15;

int n;
pair<int, int> regina[maxn];
int cnt;
bitset <maxn> col;
bitset <2*maxn> dp, ds;

void afisare() {
	++ cnt;
	if(cnt == 1) {
		for(int i = 1 ; i <= n ; ++ i)
			fout << regina[i].second << ' ';
		fout << '\n';
	}
}

inline int mabs(int x) {
	if(x < 0)
		return -x;
	return x;
}

void back(int linie) {
	if(linie == n + 1) {
		afisare();
		return ;	
	}
	for(int coloana = 1 ; coloana <= n ; ++ coloana) {
		if(!col[coloana] &&   !dp[linie + coloana - 1] 
								&& !ds[linie + n - coloana]) {
			regina[linie] = make_pair(linie, coloana);
			col[coloana] = 1;
			dp[linie + coloana - 1] = 1;
			ds[linie + n - coloana] = 1;
			back(linie + 1);
			col[coloana] = 0;
			dp[linie + coloana - 1] = 0;
			ds[linie + n - coloana] = 0;	
		}
	}
}

int main() {
	fin >> n;
	back(1);
	fout << cnt << '\n';
}
