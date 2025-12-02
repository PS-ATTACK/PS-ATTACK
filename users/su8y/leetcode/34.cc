class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        auto rit = std::upper_bound(nums.begin(), nums.end(), target);
        if (it == nums.end() || *it != target) {
            return { -1,-1 };
        }
        int start = it - nums.begin();
        int end = rit - nums.begin() - 1;

        return { start, end };
    }
};