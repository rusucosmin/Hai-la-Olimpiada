# Matrix multiplication and biconnected components

## Interview problems

* In-place random shuffle an array.
* Implement a queue using two stacks. [queue](https://infoarena.ro/problema/queue)


## Matrix multiplication

- [kfib](https://infoarena.ro/problema/kfib)
- [iepuri](https://infoarena.ro/problema/iepuri)
- [recurenta2](https://infoarena.ro/problema/recurenta2)

## Biconnected components

low[x] = min(low[x], low[y]); <--- gresit
vs
low[x] = min(low[x], level[y]); <--- corect
[Sursa](http://infoarena.ro/job_detail/601818?action=view-source) ia 100 desi pica testul:

Pe testul
```
8 9
1 2
2 3
3 4
4 5
5 1
2 6
6 7
7 8
8 2
```
Sursa gresita afiseaza
```
1
1 2 3 4 5 6 7 8
```
Corect
```
2
2 6 7 8
1 2 3 4 5
```

- [biconex](https://infoarena.ro/problema/biconex)
- [clepsidra](https://infoarena.ro/problema/clepsidra)
