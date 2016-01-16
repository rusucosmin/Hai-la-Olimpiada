





#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("permutari.in");
ofstream fout("permutari.out");

const int maxn = 20;

int n, per[maxn];

bool valid(int val, int k) {
	for(int i = 1 ; i <= k - 1 ; ++ i)
		if(per[i] == val)
			return false;
	return true;
}

void afisare() {
	for(int i = 1 ; i <= n ; ++ i)
		fout << per[i] << ' ';
	fout << '\n';
}

void back(int k) {
	if(k == n + 1) {
		afisare();
		return ;
	}
	for(int i = 1 ; i <= n ; ++ i) /// incercam toate valorile posibilie
		if(valid(i, k)) 
		{ /// returneaza 1 daca putem sa punem el i
							/// pe nivelul k
			per[k] = i;
			back(k + 1);
		}
}

int main() {
	fin >> n;
	back(1);
}
