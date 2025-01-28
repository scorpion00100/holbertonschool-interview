#!/usr/bin/python3
"""Task 0. Log parsing"""

import sys

lap = 0

status_codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

total_size = 0


def print_stats():
    """Prints statistics from the beginning"""
    print("File size: {}".format(total_size))
    for key in sorted(status_codes.keys()):
        if status_codes[key] > 0:
            print("{}: {}".format(key, status_codes[key]))


if __name__ == "__main__":
    try:
        for line in sys.stdin:
            lap += 1
            try:
                infos = line.split()
                total_size += int(infos[-1])
                code = int(infos[-2])
                if code in status_codes.keys():
                    status_codes[code] += 1
            except ValueError:
                pass
            if lap % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        print_stats()
    print_stats()
