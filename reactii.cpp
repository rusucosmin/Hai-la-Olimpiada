#include <iostream>
#include <fstream>
#include <string.h>
#include <stack>

using namespace std;

bool can(pair<int, int> v1, pair<int, int>  v2) {
	return v1.second + 1 == v2.first || v1.first == v2.second + 1;
}

pair<int, int> merge(pair<int, int> v1, pair<int, int> v2) {
	return make_pair(min(v1.first, v2.first), max(v1.second, v2.second));
}

int main() {
	ifstream fin("reactii.in");
	ofstream fout("reactii.out");

	int n, m;

	fin >> n >> m;
	for(int i = 1 ; i <= m ; ++ i) {
		stack <pair<int, int> > st;
		for(int j = 1 ; j <= n ; ++ j) {
			int x;
			fin >> x;
			pair<int, int> act = make_pair(x, x);
			while(!st.empty() && can(st.top(), act)) {
				act = merge(act, st.top());
				st.pop();
			}
			st.push(act);
		}
		fout << (st.size() == 1) << "\n";
	}
}
