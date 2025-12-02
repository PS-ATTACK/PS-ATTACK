import sys
from enum import Enum

from itertools import permutations, combinations, product, combinations_with_replacement
from collections import deque
import math
from collections import Counter

n = int(input())

book_list = []
for _ in range(n):
    book_name = sys.stdin.readline().strip()
    book_list.append(book_name)

counter = Counter(book_list)
topMost = counter.most_common()
topMost.sort(key=lambda x: (-x[1], x[0]), reverse=False)
print(topMost[0][0])
# list.sort(key=lambda x: x[1], reverse=True)
# print(list[0][0])
