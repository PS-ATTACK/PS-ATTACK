class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() ==1) return nums[0];

        int target =nums[0];
        int lo = -1, hi = nums.size();
        while(lo+1 < hi){
            int mid= lo + (hi-lo)/2;
            if(nums[mid] >= target){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        cout << hi;
        if( hi != nums.size()){
            rotate(nums.begin(), nums.begin() + hi, nums.end());
        }
        return nums[0];
    }
};