http://www.infoarena.ro/problema/subsecvente2:
	- Solutia cu cautare binara
	- Solutia cu trie: subsecvente2.cpp

http://www.infoarena.ro/problema/sub
	
A: ana
   nai
   bana

B
   cal

http://www.infoarena.ro/problema/xormax

x | y | x ^ y
0 	0 	0
0   1	1
1   0	1
1   1	0


x ^ x = 0
0 ^ x = x


O(N^3) -> fiecare subsecventa
O(N^2) -> xor-uri partiale

sum[i] = x1 ^ x2 ^ ... ^ xi

sum[i] ^ sum[j - 1] = xj ^ x j + 1 ... ^ xi

pres ca ne fixam un i

sum[i] 

caut un j astfel incat sum[j-1] sa difere fata de sum[i] in cat mai multe pozitii

O(N log N)

""
"a"
"an"
"ana"
"anaf"

dp[nod] = 1 daca playerul 0 poate castiga pornind din nod

dp[node] = 1 daca exista un fiu care are dp[fiu] = 0
dp[node] = 0 otherwise


ana
anaf
anada

http://codeforces.com/contest/456/problem/D
sursa: alotofgames.cpp
