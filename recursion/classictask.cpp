/**
    Inmultire in timp logaritmic
*/

int lgmult(int a, int b) {
    if(b == 0)
        return 0;
    int semiprod = lgmult(a, b / 2);
    semiprod = (semiprod + semiprod) % c;
    if(b % 2 == 0)
        return semiprod;
    else
        return (semiprod + a) % c
}
