import heapq
import sys
input = sys.stdin.readline

nTeam, nUniv = map(int, input().split())
ans = []
pq = list()

for i in range(nTeam):
    univ, team, solve, panerty = map(str, input().split())
    heapq.heappush(pq, (-int(solve), int(panerty), univ, team))

uniqueUniv = set()
while pq:
    solve, patnerty, univ, team = heapq.heappop(pq)
    if len(uniqueUniv) >= nUniv: break
    if univ in uniqueUniv: continue

    uniqueUniv.add(univ)
    ans.append(team)


uniqueUniv.clear()

    
print('\n'.join(ans))