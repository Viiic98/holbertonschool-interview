#!/usr/bin/python3
""" Making change """


def makeChange(coins, total):
    """ Make change

        Return: fewest number of coins needed to meet total
            - If total is 0 or less, return 0
            - If total cannot be met by any number of coins you
              have, return -1
    """
    if total <= 0:
        return 0
    coins_dic = {}
    coins = sorted(coins, reverse=True)
    for coin in coins:
        if total / coin >= 1:
            coins_dic[coin] = int(total / coin)
            total = total % coin
        if total == 0:
            break
    if total != 0:
        return -1
    return sum(coins_dic.values())
