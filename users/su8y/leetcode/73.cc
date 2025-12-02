#define pint pair<int,int>
class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        vector<pint> zeros;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 0) zeros.push_back({i,j});
            }
        }
        for(auto [y,x] : zeros){
            // 상 하 좌 우 다 0으로 바꾼다. 
            for(int i = 0 ; i < grid[0].size();i++){
                grid[y][i] = 0;
            }
            for(int i = 0 ; i < grid.size();i++){
                grid[i][x] = 0;
            }
        }
        
    }
};