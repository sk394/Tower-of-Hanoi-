# Tower of Hanoi using recursion
he Tower of Hanoi is a classic puzzle consisting of three rods and a number of disks of different sizes which can slide onto any rod. The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.

The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

1. Only one disk can be moved at a time.
2. Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack i.e. a disk can only be moved if it is the uppermost disk on a stack.
3. No disk may be placed on top of a smaller disk.

# Solutions
The Tower of Hanoi puzzle can be solved recursively using the following steps:

1. Move n-1 disks from the source rod to the auxiliary rod.
2. Move the nth disk from the source rod to the destination rod.
3. Move the n-1 disks from the auxiliary rod to the destination rod.
The above steps can be repeated for any number of disks, with the recursion ending when only one disk is left to be moved.
