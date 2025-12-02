class Solution:
    def _dfs(self, graph, idx, visited):
        visited[idx] = True
        for i in range(len(graph[idx])):
            if i == idx or graph[idx][i] == 0 or visited[i]: continue
            self._dfs(graph, i, visited)

    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        visited = [False] * len(isConnected)
        cnt = 0
        for i in range(len(isConnected)):
            if not visited[i]:
                self._dfs(isConnected, i, visited)
                cnt += 1
        return cnt