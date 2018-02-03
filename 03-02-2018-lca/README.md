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

## Programare dinamica

## RMQ
