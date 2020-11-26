#!/usr/bin/python3
""" rain """


def rain(walls):
    """ calculate how much water will be retained after it rains """
    if type(walls) is not list or len(walls) == 0:
        return 0
    n = 0
    for i in range(1, len(walls) - 1):
        n += walls[i]
    return n
