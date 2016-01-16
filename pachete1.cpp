#include <iostream>

using namespace std;

int a[1005], n, c;

int main() {
	/// citirea datelor
	cin >> n >> c;
	for(int i = 0 ; i < n ; ++ i)
		cin >> a[i];
	
	/// prelucrare
	int v = c, cnt = 1;
	for(int i = 0 ; i < n ; ++ i) {
		if(v >= a[i])
			v -= a[i];  /// v = v - a[i];
		else {
			v = c - a[i];
			cnt ++;
		}
	}
	/// afisare
	cout << cnt << '\n';
	return 0;	
}
