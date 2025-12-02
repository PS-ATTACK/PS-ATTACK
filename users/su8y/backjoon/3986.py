from itertools import permutations, combinations, product, combinations_with_replacement
from collections import deque
import math


def solve(list):
    stack = deque()
    for e in list:
        stack.append(e)
        if len(stack) >= 2 and stack[len(stack) - 1] == stack[len(stack) - 2]:
            stack.pop()
            stack.pop()
    return len(stack) == 0


n = int(input())
result = 0
for _ in range(n):
    str = list(input())
    if solve(str) :
        result += 1

print(result)
