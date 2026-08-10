class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, int m, int n){
        int dx[]={1,-1,0,0};
        int dy[]={0,0,-1,1}; 
        for(int k=0;k<4;k++){
            int ni=i+dx[k];
            int nj=j+dy[k];
            if(ni>=0 && ni<m && nj>=0 && nj<n && grid[ni][nj]=='1'){
                grid[ni][nj]='0';
                dfs(ni,nj,grid,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    dfs(i,j,grid,m,n);
                    res++;
                }
            }
        }

        return res;
    }
};
