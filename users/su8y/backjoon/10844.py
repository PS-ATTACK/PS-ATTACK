from enum import Enum

from itertools import permutations, combinations, product, combinations_with_replacement
from collections import deque
import math
from collections import Counter

'''
1 = 9
1 : 1
2 : 2
9 : 1
'''

n = int(input())
dp = [[0] * 10 for _ in range(0, n + 1)]
dp[1] = [0, 1, 1, 1, 1, 1, 1, 1, 1, 1]


def solve():
    global dp
    if n == 1:
        print(9)
        return

    for i in range(1, n):
        for j in range(0, 10):
            if j - 1 >= 0:
                dp[i + 1][j - 1] += dp[i][j]
            if j + 1 <= 9:
                dp[i + 1][j + 1] += dp[i][j]

    print(sum(dp[n]) % 1_000_000_000)


solve()
