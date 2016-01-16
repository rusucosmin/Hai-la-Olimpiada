



#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("combinari.in");
ofstream fout("combinari.out");

const int maxn = 20;

int n, k, st[maxn];

void afisare() {
	for(int i = 1 ; i <= k ; ++ i)
		fout << st[i] << ' ';
	fout << '\n';
}

void back(int p) {
	if(p == k + 1) {
		afisare();
		return ;
	}
	for(int i = st[p - 1] + 1 ; i <= n ; ++ i) {
		st[p] = i;
		back(p + 1);
	}
}

int main() {
	fin >> n >> k;
	back(1);
}
