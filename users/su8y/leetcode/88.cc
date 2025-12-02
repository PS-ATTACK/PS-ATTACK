class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ret; 

        int i1 = 0;
        int i2 = 0;
        while(i1 < m && i2 < n){
            if(nums1[i1] < nums2[i2]){
                ret.push_back(nums1[i1]);
                i1++;
            }else{
                ret.push_back(nums2[i2]);
                i2++;
            }
        }
        if(i1 == m){
            ret.insert(ret.end(), nums2.begin() + i2, nums2.end());
        }else{
            ret.insert(ret.end(), nums1.begin() + i1, nums1.begin() + m);
        }

        nums1 = ret;
    }
};