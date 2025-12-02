from itertools import permutations, combinations, product, combinations_with_replacement
from collections import deque
import math

result = 0
n = int(input())
cars = map(int, input().split())

for car in cars:
    if car == n: result += 1

print(result)