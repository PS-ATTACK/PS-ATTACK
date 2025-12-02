class Solution {

public:
    bool windowfind(int size, const vector<int>& nums, int target) {
        if(size >nums.size()) return false;
        int i, sum = 0;
        for (i = 0; i < size; i++)
            sum += nums[i];

        for (i = 0; i + size < nums.size(); i++) {
            if (sum >= target)
                return true;
            sum -= nums[i];
            sum += nums[i + size];
        }
        return sum >= target;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int lo = -1;
        int hi = nums.size() + 1;

        while (lo + 1< hi) {
            int mid = (lo + hi) / 2;

            if (windowfind(mid, nums, target)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }

        return hi > nums.size() ? 0: hi;
    }

};