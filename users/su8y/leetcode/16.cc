class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = 987654321;
        for(int i = 0; i< nums.size() - 2;i++){
            int j = i + 1; 
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target) return sum;

                if(isClosest(target, result, sum)){
                    result = sum;
                }

                if(sum < target){
                    j++;
                }else{
                    k--;
                }
            }
        }

        return result;
    }
    bool isClosest(int target, int older, int younger){
        int o_Num = target - older;
        int y_Num = target - younger;
        return abs(y_Num) < abs(o_Num);

    }
};