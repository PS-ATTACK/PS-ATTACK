class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n_size = nums.size();

        sort(nums.begin(), nums.end());
        

        for(int i=0; i<n_size-3; i++){
            for(int j=i+1; j<n_size-2; j++){
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int lo = j + 1;
                int hi = n_size-1;

                while(lo < hi){
                    if(nums[lo] + nums[hi] < newTarget){
                        lo++;
                    }else if(nums[lo] + nums[hi] > newTarget){
                        hi--;
                    }else{
                        result.push_back({ nums[i], nums[j],  nums[lo], nums[hi]  });
                        int tmplo = lo, tmphi = hi;
                        while(lo < hi && nums[lo] == nums[tmplo]) lo++;
                        while(lo < hi && nums[hi] == nums[tmphi]) hi--;
                    }
                }
                //탐색할때 값이 같다면 같은 답을 찾을 수있기 때문에 증가 시켜준다.
                while(j+1 < n_size && nums[j] == nums[j+1]) j++;  
            }
            while(i+1 < n_size && nums[i] == nums[i+1]) i++;
        }
        
        return result;
    }

};