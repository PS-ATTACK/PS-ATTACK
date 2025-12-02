class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = -1;
        int hi = nums.size() - 1;
        while(lo + 1 < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] < nums[mid + 1]){
                lo = mid;
            }else {
                hi = mid;
            }
        }
        return hi;
    }
    void peekTest(){
        vector<int> nums = {1,2,3,2};
        cout << isPeekIndex(4,nums) << endl; // false
        cout << isPeekIndex(0,nums) << endl; // false
        cout << isPeekIndex(2,nums) << endl; // true
        cout << isPeekIndex(1,nums) << endl; // false

    }
private:
    bool isPeekIndex(int i, const vector<int>& nums){
        if(i < 0 || i >= nums.size()) return false;
        if(i != 0 && nums[i] < nums[i-1])
            return false;
        if(i + 1 < nums.size()&& nums[i] < nums[i+1])
            return false;
        return true;
    }
};