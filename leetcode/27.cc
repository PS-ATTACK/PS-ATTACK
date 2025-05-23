class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (auto& num : nums) {
            if (num == val) {
                num = 9999;
            }
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() && nums[i] != 9999) {
            i++;
        }
        return i;
    }
};