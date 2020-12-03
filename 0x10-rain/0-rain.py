#!/usr/bin/python3
""" rain """


def rain(walls):
    """ calculate how much water will be retained after it rains """
    if type(walls) is not list or len(walls) == 0:
        return 0
    wall = 0
    a = 0
    n = 0
    fil = 0
    for i in range(1, len(walls)):
        if walls[i] > wall:
            n += wall * a - fil
            wall = walls[i]
            a = 0
            fil = 0
        else:
            fil += walls[i]
            a += 1
    return n
