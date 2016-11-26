def correct(s):
    cnt = 0
    for ch in s:
        if ch == '(':
            cnt += 1
        else:
            if cnt == 0:
                return 0;
            cnt -= 1
    if cnt == 0:
        return 1;
    return 0

def solveEq(eq):
    p = eq.split("=")       # split by =
    for exp in p:
        if not correct(exp):
            return 0
    return 1

def solve(s):
    s = s[:-1]              # remove .
    eqs = s.split(";")      # split by ;
    for eq in eqs:
        print(solveEq(eq))

solve("()=;()()=(((())))()=()(())().")
