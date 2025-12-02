class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int ret=0;
        int w,h;
        while(l<r){
            //54ms 87.45, 61.71MB, 27.30%
            w=r-l;
            h=min(height[l], height[r]);
            ret = max(ret, w*h);
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return ret;
    }
};