#!/usr/bin/python3
""" Prime Game """


def isWinner(x, nums):
    """ Prime Game """
    if not nums or x < 1:
        return None
    n = max(nums)
    game = [True for _ in range(max(n + 1, 2))]
    for i in range(2, int(pow(n, 0.5)) + 1):
        if not game[i]:
            continue
        for j in range(i * i, n + 1, i):
            game[j] = False
    game[0] = game[1] = False
    c = 0
    for i in range(len(game)):
        if game[i]:
            c += 1
        game[i] = c
    pl = 0
    for n in nums:
        pl += game[n] % 2 == 1
    if pl * 2 == len(nums):
        return None
    if pl * 2 > len(nums):
        return "Maria"
    return "Ben"
