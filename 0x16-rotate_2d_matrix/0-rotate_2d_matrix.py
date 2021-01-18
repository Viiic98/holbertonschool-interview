#!/usr/bin/python3
""" Rotate 2D Matrix """


def rotate_2d_matrix(matrix):
    """ Rotate 2D Matrix

        The matrix must be edited in-place.
    """
    N = len(matrix)
    for x in range(N // 2):
        for y in range(x, N - x - 1):
            temp = matrix[x][y]

            matrix[x][y] = matrix[N - 1 - y][x]
            matrix[N - 1 - y][x] = matrix[N - 1 - x][N - 1 - y]
            matrix[N - 1 - x][N - 1 - y] = matrix[y][N - 1 - x]
            matrix[y][N - 1 - x] = temp
