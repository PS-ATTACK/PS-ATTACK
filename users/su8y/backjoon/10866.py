import sys
from enum import Enum

from itertools import permutations, combinations, product, combinations_with_replacement
from collections import deque
import math


class Command(Enum):
    push_front = 'push_front'
    push_back = 'push_back'
    pop_front = 'pop_front'
    pop_back = 'pop_back'
    size = 'size'
    empty = 'empty'
    front = 'front'
    back = 'back'


deque = deque()

n = int(input())


def push_front(n):
    deque.appendleft(n)


def push_back(n):
    deque.append(n)


def pop_front():
    if (not deque):
        sys.stdout.write("-1\n")
        return
    sys.stdout.write(str(deque.popleft())+"\n")


def pop_back():
    if (not deque):
        sys.stdout.write("-1\n")
        return
    sys.stdout.write(str(deque.pop())+"\n")


def front():
    if (not deque):
        sys.stdout.write("-1\n")
        return
    sys.stdout.write(str(deque[0])+"\n")


def back():
    if (not deque):
        sys.stdout.write("-1\n")
        return
    sys.stdout.write(str(deque[len(deque) - 1])+"\n")


def size():
    sys.stdout.write(str(len(deque))+"\n")


def empty():
    if (not deque):
        sys.stdout.write("1\n")
    else:
        sys.stdout.write("0\n")


for _ in range(n):
    command = sys.stdin.readline().split()
    if command[0].__contains__(Command.push_front.value):
        push_front(int(command[1]))
    elif command[0].__contains__(Command.push_back.value):
        push_back(int(command[1]))
    elif command[0] == Command.pop_front.value:
        pop_front()
    elif command[0] == Command.pop_back.value:
        pop_back()
    elif command[0] == Command.size.value:
        size()
    elif command[0] == Command.empty.value:
        empty()
    elif command[0] == Command.back.value:
        back()
    elif command[0] == Command.front.value:
        front()
    else:
        sys.stdout.write("Not found value in Command(Enum).class"+"\n")
