class Solution {
    public int lengthOfLIS(int[] nums) {
        List<Integer> dp = new ArrayList<>();
        //처음에는 무조건 하나가 들어간다ㅓ.
        dp.add(nums[0]);
        int idx;
        int max = 1;
        for(int i = 1 ; i < nums.length;i++){
            if((idx = lower_bound(dp,nums[i])) == dp.size()){
                dp.add(nums[i]);
            }else{
                dp.set(idx, nums[i]);
            }
            nums[i] = idx + 1;
            max = Math.max(max , idx + 1);
        }
        return max;
    }
    public int lower_bound(List<Integer> dp , int target){
        int begin = 0 ;
        int end = dp.size();

        while(begin < end){
            int mid = (begin + end) / 2;
            if(dp.get(mid) >= target){
                end = mid;
            }else{
                begin = mid + 1;

            }
        }
        return end;
    }
}