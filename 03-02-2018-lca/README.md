# LCA

[Lowest common ancestor](https://www.infoarena.ro/problema/lca)

## Brute
Pasi:
  1. Aducem nodurile la aceeasi adancime
  ```cpp
  while(deep[x] > deep[y]) {
    x = dad[x];
  }
  while(deep[y] > deep[x]) {
    y = dad[y];
  }
  ```
  2. Mergem in sus (in paralel) cu fiecare dintre noduri, pana cand dam de
  acelasi nod, care reprezinta si LCA-ul nodurilor noastre.
  ```cpp
  while(x != y) {
    x = dad[x];
    y = dad[y];
  }
  return x; // x (sau y) este lca-ul nodurilor initiale
  ```
**Aparent ia 90 puncte pe infoarena!!**[sursa](https://www.infoarena.ro/job_detail/2120973)

## Smenul lui Batog
[LCA in sqrt(N)](https://www.infoarena.ro/multe-smenuri-de-programare-in-cc-si-nu-numai)

## Programare dinamica
### Stramosi
[Stramosi](https://infoarena.ro/problema/stramosi)

Determinarea celui de-al x-lea stramos al lui y in complexitate `O(log(N))`

Dinamica:
```
dp[i][j] = al 2^i lea stramos al nodului j

dp[0][j] = tatal nodului j
dp[i][j] = dp[i - 1][ dp[i - 1][j] ]
```
Recurenta se traduce:
```
al 2^i lea stramos al lui j, este al 2^(i-1) lea stramos al celui de-al 2^(i-1) lea stramos a lui j
```
Exemplu:
```
bunicul tau e tatal tatalui tau
```
Calcularea dinamicii
```cpp
for(int i = 1; (1 << i) <= n; ++ i) {
  for(int j = 1; j <= n; ++ j) {
    dp[i][j] = dp[i - 1][ dp[i - 1][j] ];
  }
}
```
Determinarea celui de-al `p`-lea stramos al lui `q`:
```cpp
int stramos(int p, int q) {
  for(int bit = 0; (1 << bit) <= n; ++ bit) {
    if(p & (1 << bit)) {
      q = dp[bit][q];
    }
  }
  return q;
}
```

## RMQ
