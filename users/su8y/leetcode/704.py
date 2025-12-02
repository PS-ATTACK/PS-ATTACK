class Solution:
    def search(self, nums: List[int], target: int) -> int:
        idx = bisect.bisect_left(nums, target)

        if idx >= 0 and idx < len(nums) and nums[idx] == target: return idx 
        return -1