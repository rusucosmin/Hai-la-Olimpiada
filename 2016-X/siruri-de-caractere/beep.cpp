#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("beep.in");
ofstream fout("beep.out");

int main() {
    string interzis;
    string act;

    fin >> interzis;
    while(fin >> act) {
        if(act == interzis)
            act = "beep";
        fout << act << ' ';
    }
    return 0;
}
