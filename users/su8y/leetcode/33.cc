class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = -1, hi = nums.size();
        int highMin = nums[0];

        while( lo+1 < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] >= highMin){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        int pivot = hi;
        rotate(nums.begin(), nums.begin() + pivot, nums.end());


        lo = -1, hi = nums.size() -1;
        while( lo+1 < hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] < target){
                lo = mid;
            }else{
                hi = mid;
            }
        }

        return nums[hi] == target ? (hi + pivot) % nums.size() : - 1;



    }
private:

};