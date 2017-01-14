#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stack>

using namespace std;

stack<int> st1, st2;

void push_back(int x) {
    printf(" read(%d)", x);
    printf(" push(1,%d)\n", x);
    st1.push(x);
}

void move() {
    while(st1.size() > 0) {
        printf(" pop(1)");
        int x = st1.top();
        st1.pop();
        printf(" push(2,%d)", x);
        st2.push(x);
    }
}

void pop_back() {
    if(st2.size() == 0)
        move();
    int x = st2.top();
    st2.pop();
    printf(" pop(2)");
    printf(" write(%d)\n", x);
}

int main() {
    freopen("queue.in", "r", stdin);
    freopen("queue.out", "w", stdout);

    int n;
    scanf("%d\n", &n);

    for(int i = 0; i < n; ++ i) {
        printf("%d:", i + 1);
        int x;
        char a, b, s[100];
        scanf("%c%c", &a, &b);
        if(a == 'p' && b == 'u') {
            scanf("sh_back(%d)\n", &x);
            push_back(x);
        }
        else {
            scanf("%s\n", s);
            pop_back();
        }
    }
}
