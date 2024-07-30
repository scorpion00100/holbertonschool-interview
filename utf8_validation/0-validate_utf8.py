#!/usr/bin/python3
"""0-validate_utf8 module"""


def count_leading_ones(n: int) -> int:
    """Counts the number of leading ones in the binary representation of a byte."""
    count = 0
    for i in range(7, -1, -1):
        if n & (1 << i):
            count += 1
        else:
            break
    return count


def validUTF8(data) -> bool:
    """
    Determines if a given data set represents
    a valid UTF-8 encoding.
    Args:
        data: A list of integers where each integer
        represents one byte (8 bits) of data.
    Returns:
        bool: True if data is a valid UTF-8 encoding,
        else False.
    """
    count = 0
    for d in data:
        if count == 0:
            count = count_leading_ones(d)
            if count == 0:
                continue
            if count == 1 or count > 4:
                return False
            count -= 1
        else:
            if count_leading_ones(d) != 1:
                return False
            count -= 1
    return count == 0
