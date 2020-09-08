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
    status = {}

    try:
        for line in sys.stdin:
            status_code = line.split()[7]
            if status_code in status:
                status[status_code] += 1
            else:
                status[status_code] = 1
            file_size += int(line.split()[8])

            if i % 10 == 0:
                print("File size: ", file_size)
                for k, v in sorted(status.items()):
                    print(k, ": ", v)
            i += 1
    except KeyboardInterrupt:
        print("File size: ", file_size)
        for k, v in sorted(status.items()):
            print(k, ": ", v)
        raise
