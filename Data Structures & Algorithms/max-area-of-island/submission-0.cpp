class Solution {
public:
    vector<int> di = {1,-1,0,0};
    vector<int> dj = {0,0,-1,1};
    void dfs(int i, int j, vector<vector<int>> &grid, int m, int n, int &area) {
        grid[i][j]=0;
        for(int k=0;k<4;k++){
            int ni = i + di[k];
            int nj = j + dj[k];
            if(ni>=0 && nj>=0 && nj<n && ni<m && grid[ni][nj]==1){
                // grid[ni][nj]=0;
                area++;
                dfs(ni,nj,grid,m,n,area);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;

        // queue<pair<int,int>> q;
        int m = grid.size(), n = grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area=1;
                    dfs(i,j,grid,m,n,area);
                    maxArea=max(area,maxArea);
                }
            }
        }

        return maxArea;
    }
};
