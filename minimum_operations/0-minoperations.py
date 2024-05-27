#!/usr/bin/python3
"""Minimum Operations"""


def minOperations(n):
    """
    Method that calculates the fewest number of operations
    """
    if n <= 1:
        return 0

    minOperations = 0

    while n % 2 == 0:
        minOperations += 2
        n /= 2

    i = 3
    while i * i <= n:
        while n % i == 0:
            minOperations += i
            n /= i
        i += 2
    if n > 2:
        minOperations += n

    return int(minOperations)
