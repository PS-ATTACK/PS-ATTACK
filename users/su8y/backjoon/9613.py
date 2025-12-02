from enum import Enum

from itertools import permutations, combinations, product, combinations_with_replacement
from collections import deque
import math
from collections import Counter

'''
3
4 10 20 30 40
3 7 5 12
3 125 15 25'''

output = []
n = int(input())

for i in range(n):
    numbers = list(map(int, input().split()))
    result = 0
    for j in range(1,len(numbers)):
        for k in range(j+1, len(numbers)):
            res =math.gcd(numbers[j], numbers[k])
            result += res
    output.append(str(result) + "\n")

print(''.join(output))