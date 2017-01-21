
dp[i] = suma lunigimilor cuvintelor care NU le stie din sirul care se termina
    pe pozitia i

dp[0] = 0
dp[i] = min(dp[i - 1] + 1,
            dp[k - 1] if match(k, i)) 1 <= k <= i

1...(i - 1)   .... i

dp[0] = 0;
for(int i = 1; i <= n; ++ i) {
    dp[i] = dp[i - 1] + 1;
    for(int k = 1; k <= i; ++ k) {
        if(match[k][i])
            dp[i] = min(dp[i], dp[k - 1]);
    }
}
cout << dp[n];


bool match[i][j] -> true daca exista un cuvant
    care se potriveste pe secventa [i, j] in text


///tastatura

dp[i] = numarul minim de cuvinte astfel incat sa acoperim secventa
    [1..i]

dp[0] = 0
dp[i] = min(dp[i - 1] + 1 ///apas o tasta de la 0 la 9
   dp[k - 1]) if(match(k, i)) i <= k <= i
rasp: dp[n]

    s[0] = s[1] = 0;
    int k = 0;
    for(int i = 2; i <= n ++ i) {
        ///cat trebuie sa mergem inapoi?
        while(k > 0 && s[k + 1] != s[i])
            k = pi[k];
        ///ori k == 0 ori s[k + 1] == s[i] ori ambele
        if(s[k + 1] == s[i])
            ++ k;
        if
        pi[i] = k;
    }
}

void potriviri(char text[maxn], char s[maxn], int pi[maxn]) {
    int k = 0;
    for(int i = 1; i <= n; ++ i) {
        while(k > 0 && s[k + 1] != text[i])
            k = pi[k];
        if(s[k + 1] == text[i])
            ++ k;
        if(k == m) {
            cout << "potrivire: " << i - m << '\n';
            k = pi[k];
        }
    }
}
