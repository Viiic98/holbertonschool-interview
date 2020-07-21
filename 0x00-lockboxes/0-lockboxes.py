#!/usr/bin/python3


def canUnlockAll(boxes):
    keys = []
    keys = boxes[0]
    opened = [0]

    for key in keys:
        if key not in opened:
            for val in boxes[key]:
                if val not in keys:
                    keys.append(val)
            opened.append(key)

    if len(opened) >= len(boxes) - 1:
        return True
    else:
        return False
