class Solution:


    def exist(self, board: List[List[str]], word: str) -> bool:
        dx = [-1, 1, 0, 0]; dy = [0, 0, -1, 1]
        n = len(board); m = len(board[0])
        visited = set()
        def dfs(y, x, idx):
            if idx >= len(word): return True 
            for i in range(4):
                ny = y + dy[i]; nx = x + dx[i]
                if not 0 <= ny < n or not 0 <= nx < m or (ny, nx) in visited or board[ny][nx] != word[idx]: continue
                visited.add((ny,nx))
                if dfs(ny, nx, idx + 1): return True
                visited.remove((ny,nx))
    
            return False
    
        for i in range(n):
            for j in range(m):
                if board[i][j] == word[0]:
                    visited.add((i,j))
                    if dfs(i, j ,1):
                        return True # 첫번째부터 찾기시작
                    visited.remove((i,j))

        return False

        