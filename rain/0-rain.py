#!/usr/bin/python3
"""Rain module"""

def rain(walls):
    """
    Function that calculates how many square units
    of water will be retained after it rains
    """
    size = len(walls)
    if size == 0:
        return 0

    left_max = [0] * size
    right_max = [0] * size

    left_max[0] = walls[0]
    for i in range(1, size):
        left_max[i] = max(left_max[i-1], walls[i])

    right_max[size-1] = walls[size-1]
    for i in range(size-2, -1, -1):
        right_max[i] = max(right_max[i+1], walls[i])

    result = 0
    for i in range(size):
        result += min(left_max[i], right_max[i]) - walls[i]

    return result
