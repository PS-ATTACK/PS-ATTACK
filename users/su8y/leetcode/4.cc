class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int len = nums1.size();
        double sum = nums1[len/ 2];
        
        if(len % 2 ==0){
            sum += nums1[(len/2) -1];
            sum /= 2;
        }
        return sum;
    }
};