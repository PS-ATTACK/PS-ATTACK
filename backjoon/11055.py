from enum import Enum

from itertools import permutations, combinations, product, combinations_with_replacement
from collections import deque
import math
from collections import Counter

'''
10
1 100 2 50 60 3 5 6 7 8
1 100 100 100 
'''


n = int(input())

A = list(map(int, input().split()))
DP = [0] * n

DP[0] = A[0]

for i in range(n):
    for j in range(i):
        if( A[i] > A[j] ):
            DP[i] = max(DP[i], DP[j] + A[i])
        else:
            DP[i] = max(DP[i],  A[i])

print(max(DP))

