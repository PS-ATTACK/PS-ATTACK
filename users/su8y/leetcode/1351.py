class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        def sub(row):
            l = 0; r = len(row) - 1
            answer = len(row)
            while l <= r:
                mid = (l+r) // 2
                if row[mid] < 0:
                    answer = mid
                    r = mid - 1
                else:
                    l = mid + 1
            return len(row) - answer
        cnt = 0
        for row in grid:
            cnt += sub(row)
        return cnt

        