#Potrivirea sirurilor

##Discutii

abac
aaabac

'a' - 1
'b' - 2
..
'z' - 26

base = 26


abracadabra
dabstep

8
10
14
13
15
19
18
20

2
4
-1
2
4
-1
2

##Link-uri Utile
- [TopCoder Rabin-Karp si KMP](https://www.topcoder.com/community/data-science/data-science-tutorials/introduction-to-string-searching-algorithms/)
- [InfoArena](http://www.infoarena.ro/problema/strmatch)
- Un alt algoritm interesant este [ZAlgorithm](http://www.infoarena.ro/zalgorithm), prezentat foarte bine in [acest](http://www.infoarena.ro/zalgorithm) articol

##Probleme
- [Prefix](http://www.infoarena.ro/problema/prefix)
- [Palindrom](http://www.infoarena.ro/problema/palindrom)
- [Reguli](http://www.infoarena.ro/problema/reguli)
- [Carte](http://www.infoarena.ro/problema/carte). Hint: string matching + dp
    - dp[i] = numarul minim de caractere care raman pe afara, daca impartim in mod convenabil primele i caractere
    - d[0] = 0
    - pentru fiecare pozitie posibila i, vezi ce cuvant se poate potrivi perfect pana pe pozitia i
        if(match[j][i])
            dp[i] = max(dp[i], dp[i - lung[j] + lung[j]);
- [Tastatura](http://www.infoarena.ro/problema/tastatura)
- [Map](http://www.infoarena.ro/problema/map)
- [Potrivire](http://www.infoarena.ro/problema/potrivire)
- [Secv10](http://www.infoarena.ro/problema/secv10)
- [Subsecvente2](http://www.infoarena.ro/problema/subsecvente2)
