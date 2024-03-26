#!/usr/bin/python3

def canUnlockAll(boxes):
    """Determines if all the boxes can be unlocked."""

    if boxes == []:
        return True

    # When we get the key of a box, we put it in this list.
    boxes_to_unlock = [0]

    # This list contains the number of the boxes we can unlock.
    unlocked_boxes = [False for box in boxes]

    unlocked_boxes[0] = True

    while len(boxes_to_unlock) > 0:
        # We take the first key of boxes_to_unlock as index.
        index = boxes_to_unlock[0]

        # We check the keys of boxes_index
        boxes_to_unlock = add_keys(boxes_to_unlock, unlocked_boxes, boxes, index)

        # We do this to mark the box at the index.
        unlocked_boxes[index] = True

        # we can remove its key from boxes_to_unlock.
        boxes_to_unlock.pop(0)

    # We return True if all boxes can be unlocked.
    return all(unlocked_boxes)


def add_keys(boxes_to_unlock, unlocked_boxes, boxes, index):
    """Method that adds keys to boxes_to_unlock"""
    for key in boxes[index]:    
        # we add its key to boxes_to_unlock
        if (key < len(boxes) and not unlocked_boxes[key] and
                key not in boxes_to_unlock):
            boxes_to_unlock.append(key)
    return boxes_to_unlock