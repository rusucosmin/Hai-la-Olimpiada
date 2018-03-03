#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int a[2][2] = {
  {0, 1},
  {1, 1}
};

int ret[2][2] = {
  {1, 0},
  {0, 1},
};

int c[2][2];

inline void matmult(int a[2][2], int b[2][2], int c[2][2]) {
  for(int i = 0; i < 2; ++ i) {
    for(int j = 0; j < 2; ++ j) {
      c[i][j] = 0;
      for(int k = 0; k < 2 ; ++ k) {
        c[i][j] = (c[i][j] + (1LL * a[i][k] * b[k][j]) % 666013) % 666013;
      }
    }
  }
}

inline int fib(int n) {
  n --;
  for( ; n ; n >>= 1) {
    if(n & 1) {
      matmult(a, ret, c);
      memcpy(ret, c, sizeof(ret));
    }
    matmult(a, a, c);
    memcpy(a, c, sizeof(a));
  }
  return ret[1][1];
}

int main() {
  ifstream fin("kfib.in");
  ofstream fout("kfib.out");

  int n;
  fin >> n;

  fout << fib(n) << '\n';
}
