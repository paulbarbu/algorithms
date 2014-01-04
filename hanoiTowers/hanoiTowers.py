#! /usr/bin/env python3

def hanoi(n, source, helper, dest):
    if n == 1:
        print(source + '-' + dest)
    else:
        hanoi(n-1, source, dest, helper)
        print(source + '-' + dest)
        hanoi(n-1, helper, source, dest)

if '__main__' == __name__:
    hanoi(4, 'a', 'b', 'c')

