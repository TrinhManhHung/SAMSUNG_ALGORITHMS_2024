from math import *

def rev(n):
    s = str(n)
    s = s[::-1]
    return int(s)
if __name__ == '__main__':
    t = int(input())
    for T in range(t):
        n = int(input())
        cnt = 0
        while (n%7 != 0 and cnt <= 1000):
            n += rev(n)
            cnt += 1

        if n % 7 == 0: print(n)
        else: print(-1)




