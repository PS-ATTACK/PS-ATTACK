1158from itertools import permutations, combinations, product, combinations_with_replacement
from collections import deque
import math

n, k = map(int, input().split())

result = []
persons = [i for i in range(1, n + 1)]
q = deque(persons)
cnt = 0
while len(q) != 0:
    for _ in range(k - 1):
        element = q.popleft()
        q.append(element)
    result.append(q.popleft())



resultString = ", ".join(map(str, result))
print(f"<{resultString}>")
