#!/usr/bin/python3
""" Min operations """


def minOperations(n):
    """ Min operations to reach 'H' character of n """
    if n <= 1:
        return 0
    x = 2
    y = 1
    res = 2
    if n == x:
        return x
    else:
        while (1):
            if n % x == 0:
                x, y = x + x, x
                res += 2
            else:
                x += y
                res += 1
            if x == n:
                return res
