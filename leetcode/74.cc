class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int size, colSize, rowSize;
        rowSize = matrix[0].size();
        colSize = matrix.size();
        size = rowSize * colSize;
        
        int lo,hi,mid;
        lo = -1, hi = size-1;
        while(lo + 1 < hi){
            int mid = lo + (hi - lo)/2;
            int midCol = mid / rowSize;
            int midRow = mid % rowSize;
            if(matrix[midCol][midRow] < target){
                lo = mid;
            }else{
                hi = mid;
            }
        }
        return matrix[hi/rowSize][hi%rowSize] == target;
    }
};