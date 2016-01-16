





#include <iostream>
#include <fstream>
#include <stack>
#include <bitset>

using namespace std;

const int maxn = 20;

int n;
bitset <maxn> used; 
/**
	used.count() = returneaza numarul valorilor egale cu 1
	used.reset() = reseteaza bitii la 0

	Obs:
		bool x;
		fin >> x;
		used[i] = x;


		fin >> used[i];   NOT OK!

*/

ifstream fin("submultimi.in");
ofstream fout("submultimi.out");

void back(int k) {
	if(k == n + 1) {
		/// afisarea	
		bool ok = false;
		for(int i = 1 ; i <= n ; ++ i)
			if(used[i] == 1) {
				fout << i << ' ';
				ok = true;
			}
		if(ok)
			fout << '\n';
		return ;
	}
	/// nu alegem elementul
	used[k] = 0;
	back(k + 1);
	/// alegem elementul
	used[k] = 1;
	back(k + 1);
	used[k] = 0;
}

int main() {
	fin >> n;
	back(1);
}
