#!/usr/bin/python3
""" reads stdin line by line and computes metrics
    Input format:
    <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
    <status code> <file size>
"""
from signal import signal, SIGINT
import sys

if __name__ == "__main__":
    i = 1
    file_size = 0
    status_list = {"200": 0,
                   "301": 0,
                   "400": 0,
                   "401": 0,
                   "403": 0,
                   "404": 0,
                   "405": 0,
                   "500": 0}

    try:
        for line in sys.stdin:
            status_code = line.split()[7]
            status_list[status_code] += 1
            file_size += int(line.split()[8])

            if i % 10 == 0:
                print("File size: {}".format(file_size))
                for k, v in sorted(status_list.items()):
                    if v:
                        print("{}: {}".format(k, v))
            i += 1
    except KeyboardInterrupt:
        print("File size: ", file_size)
        for k, v in sorted(status_list.items()):
            if v:
                print(k, ": ", v)
        raise
