#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ Pascal's Triangle

        Returns an empty list if n <= 0
        You can assume n will be always an integer
    """
    if n <= 0:
        return []
    pascal_t = [[1]]
    for i in range(n - 1):
        row = []
        for j in range(i + 2):
            if j - 1 < 0:
                a = 0
            else:
                a = pascal_t[i][j - 1]
            if j >= len(pascal_t[i]):
                b = 0
            else:
                b = pascal_t[i][j]
            c = a + b
            row.append(c)
        pascal_t.append(row)
    return pascal_t
