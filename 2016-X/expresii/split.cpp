#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string s, char delim) {
    string act = "";
    vector <string> ret;
    for(int i = 0; i < s.size(); ++ i)
        if(s[i] == delim) { /// daca s[i] e delimitatorul TODO: daca se afla printre delimitarori
            if(act != "")
                ret.push_back(act);
            act = "";
        }
        else
            act.push_back(s[i]);
    if(act != "")
        ret.push_back(act);
    return ret;
}

int main() {
    vector <string> x = split("ana are mere", ' ');
    for(auto el : x)
        cerr << el << '\n';
    return 0;
}
