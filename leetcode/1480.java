class Solution {
    public int[] runningSum(int[] nums) {
        // int result[] = new int[nums.length];
        // for(int i = 0; i < nums.length ; i++) {
        //     if( i - 1 < 0)result[i] = nums[i];
        //     else result[i] = result[i-1] + nums[i];
        // }
        // return result;
        return IntStream
            .range(0,nums.length)
            .map(i -> {
                return i ==0 ? nums[i] : (nums[i] += nums[i-1]);
            })
            .toArray();
    }
}