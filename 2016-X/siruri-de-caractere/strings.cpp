#include <iostream>
#include <fstream>

using namespace std;

const string delim = " ,.!?|-";

ifstream fin("strings.in");
ofstream fout("strings.out");

inline bool find(string s, char c) {
    for(int i = 0; i < s.size(); ++ i)
        if(s[i] == c)
            return 1;
    return 0;
}

int main() {
    string cuv, line, v[100];
    int cnt = 0;

    while(getline(fin, line)) {
        cout << line << '\n';
        cnt = 0;
        for(int i = 0; i < line.size(); ++ i) {
            if(find(delim, line[i])) {
                if(cuv != "") {
                    v[++ cnt] = cuv;
                    cuv = "";
                }
            }
            else {
                cuv.push_back(line[i]);
            }
        }
        if(cuv != "") {
            v[++ cnt] = cuv;
            cuv = "";
        }

        for(int i = 1; i <= cnt; ++ i)
            cout << v[i] << '\n';
    }
    return 0;
}
