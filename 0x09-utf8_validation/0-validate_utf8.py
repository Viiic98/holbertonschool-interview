#!/usr/bin/python3
""" UTF-8 Validation """


def validUTF8(data):
    """ determines if a given data set represents a valid UTF-8 encoding

        Return: True if data is a valid UTF-8 encoding, else return False
    """
    n_bytes = 0
    for x in data:
        m = 1 << 7
        if n_bytes == 0:
            while x & m:
                n_bytes += 1
                m = m >> 1
            if n_bytes == 1 or n_bytes > 4:
                return False
            if n_bytes:
                n_bytes -= 1
        else:
            if x & m and not x & m >> 1:
                n_bytes -= 1
            elif x & m >> 1:
                return False
    return n_bytes == 0
