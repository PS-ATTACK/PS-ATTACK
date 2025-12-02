"""
dfs로 1-(n-1) 번 까지 있으면 우선 만들기를 시작한다. 만약 부품을 만들지 못했으면 우선 대기하고
예를 들어
7 번에 5번이 2개
5 번에는 1번이 3개면
7번을 만들기 위해서는 6번이 필요하기 때문에 5번을 2개 만든다고 생각하고
tmparr 에 5번을 1 추가한다.
그런식으로 밑으로 쭉쭉내려간다
"""
from collections import deque

N: int = 0
M: int = 0
connect: list
needs: list
ingress: list
q = deque()


def myInput():
    global N, M, ingress, connect, needs
    N = int(input())
    connect = [[] for _ in range(N + 1)]
    needs = [[0] * (N + 1) for _ in range(N + 1)]
    M = int(input())
    ingress = [0] * (N + 1)

    for _ in range(M):
        x, y, z = map(int, input().split(" "))
        connect[y].append([x, z])
        ingress[x] += 1


myInput()

for i in range(1, N + 1):
    if ingress[i] == 0:
        q.append(i)

while q:
    now = q.popleft()
    # 만들어야하는 제품인데
    for next, next_need in connect[now]:
        # 현재 다음으로 바라보고있는 부품이 지금 만들어야되는것만 해당되면 그냥 now에 값만 넣어준다.
        if needs[now].count(0) ==N + 1:
            needs[next][now] += next_need
            # 현 제품이 중간 부품이면
        else:
            for i in range(1, N + 1):
                needs[next][i] += needs[now][i] * next_need
            # 차수 -1
        ingress[next] -= 1
        if ingress[next] == 0:
            q.append(next)

for x in enumerate(needs[N]):
    if x[1] > 0:
        print(*x)
