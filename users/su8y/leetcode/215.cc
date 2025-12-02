class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        int ret; 
        while(k--){
            ret = q.top();
            q.pop();
        }
        return ret;
    }
};