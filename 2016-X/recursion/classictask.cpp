#include <iostream>
#include <fstream>

using namespace std;

typedef long long var;

/// returneaza (a * b) % c in O(logB) timp
var lgMul(var a, var b, var c) {
    if(b == 0)
        return 0;
    if(b == 1)
        return a % c;
    var aux = lgMul(a, b / 2, c);
    if(b % 2 == 0)
        return (aux + aux) % c;
    return ((a + aux) % c + aux) % c;
}

/// returneaza (a ^ b) % c in O(logB) timp
var lgPut(var a, var b, var c) {
    if(b == 1)
        return a % c;
    var aux = lgPut(a, b / 2, c);
    var aux_2 = lgMul(aux, aux, c);
    if(b % 2 == 0)
        return aux_2;
    return lgMul(aux_2, a, c);
}

int main() {
    ifstream fin("classictask.in");
    ofstream fout("classictask.out");

    var a, b, c;
    fin >> a >> b >> c;
    fout << lgPut(a, b, c);
    return 0;
}
