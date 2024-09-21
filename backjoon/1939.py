import sys
import queue

input = sys.stdin.readline

max = 1_000_000_000

N, M = map(int, input().split())

graph = [[] for _ in range(N + 1)]
# N 은 공장개수
for i in range(M):
    a, b, c = map(int, input().split())
    graph[a].append([b, c])
    graph[b].append([a, c])

start, end = map(int, input().split())


# A => B 인데 C만큼의 중량을 버틸수 있는 다리다. 모든 다리는 양방향이다.

def binary_search(n):
    lo = 0
    hi = 1000000001
    while lo + 1 < hi:
        mid = (lo + hi) // 2

        if check(mid):
            lo = mid
        else:
            hi = mid
    return hi


def check(weight):
    visited = [False] * (N+1)
    q = queue.Queue()
    q.put(start)
    visited[start] = True

    while not q.empty():
        n = q.get()
        if n == end:
            return True
        for i in graph[n]:
            if i[1] > weight and not visited[i[0]]:
                q.put(i[0])
                visited[i[0]] = True
    return False


print(binary_search(N))
