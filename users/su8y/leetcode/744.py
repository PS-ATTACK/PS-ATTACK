class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        l = 0
        r = len(letters) - 1
        answer = 0
        while l <= r:
            mid = (l + r) // 2
            if letters[mid] > target:
                answer = mid
                r = mid - 1
            else:
                l = mid + 1
        return letters[answer]