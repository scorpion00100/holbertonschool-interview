#!/usr/bin/python3
import sys


def is_safe(coords, row, col):
    """ queens puzzle is the challenge
    """
    rows = []
    cols = []
    diag_r = []
    diag_l = []

    for r, c in coords:
        rows.append(r)
        cols.append(c)
        diag_r.append(r + c)
        diag_l.append(r - c)

    if row in rows or col in cols:
        return False

    if (row + col) in diag_r or (row - col) in diag_l:
        return False

    return True


def solve_n_queens_util(coords, row, N):
    if row == N:
        print(coords)
        return True

    res = False
    for col in range(N):
        if is_safe(coords, row, col):
            coords.append([row, col])
            res = solve_n_queens_util(coords, row + 1, N) or res
            coords.pop()

    return res


def solve_n_queens(N):
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    coords = []
    if not solve_n_queens_util(coords, 0, N):
        print("No solution exists")


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
        solve_n_queens(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
