#!/usr/bin/python3
""" NQueens """
import sys


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    N = int(sys.argv[1])
    if type(N) is not int:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)

    def printSolution(board):
        """ Print indices of a solved board """
        print("[", end="")
        for i in range(N):
            for j in range(N):
                if board[i][j] == 1:
                    if i + 1 == N:
                        print("[{}, {}]".format(i, j), end="")
                    else:
                        print("[{}, {}], ".format(i, j), end="")
        print("]")

    def safe(board, row, col):
        """ Check if is a safe space """

        for i in range(col):
            if board[row][i] == 1:
                return False

        for i, j in zip(range(row, -1, -1),
                        range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        for i, j in zip(range(row, N, 1),
                        range(col, -1, -1)):
            if board[i][j] == 1:
                return False

        return True

    def solve(board, col):
        """ Solve a NQueens board """
        if col >= N:
            printSolution(board)
            return False

        for i in range(N):

            if safe(board, i, col):

                board[i][col] = 1

                if solve(board, col + 1):
                    return True

                board[i][col] = 0

        return False

    board = [[0]*N for i in range(N)]
    solve(board, 0)
