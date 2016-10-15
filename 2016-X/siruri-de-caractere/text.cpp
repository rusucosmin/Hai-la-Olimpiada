#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("text.in");
    ofstream fout("text.out");

    string s;
    getline(fin, s);
    return 0;
}
