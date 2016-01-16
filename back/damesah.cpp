



#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("damesah.in");
ofstream fout("damesah.out");

const int maxn = 15;

int n;
pair<int, int> regina[maxn];

void afisare() {
	cout << "Avem reginele: \n";
	for(int i = 1 ; i <= n ; ++ i)
		cout << regina[i].first << ' ' << regina[i].second << '\n';
}

inline int mabs(int x) {
	if(x < 0)
		return -x;
	return x;
}

bool valid(int ri, int rj, int nivel) {
	for(int i = 1 ; i < nivel ; ++ i)
		if(rj == regina[i].second || mabs(ri - regina[i].first) ==
									mabs(rj - regina[i].second))
			return false;
	return true;
}

void back(int linie) {
	if(linie == n + 1) {
		afisare();
		return ;	
	}
	for(int coloana = 1 ; coloana <= n ; ++ coloana) {
		if(valid(linie, coloana, linie)) {
			regina[linie] = make_pair(linie, coloana);
			back(linie + 1);
		}
	}
}

int main() {
	fin >> n;
	back(1);
}
