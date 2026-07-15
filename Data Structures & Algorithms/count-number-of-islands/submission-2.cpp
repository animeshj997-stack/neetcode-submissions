class Solution {
public:
    int m, n;
  
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        m = grid.size();
        n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    res++;
                    q.push({i,j});
                    bfs(grid,q);
                }
            }
        }

        return res;
    }

    void bfs(vector<vector<char>> &grid, queue<pair<int,int>> &q){
        int di[]={-1,1,0,0};
        int dj[]={0,0,-1,1};
        while(!q.empty()){
            auto it = q.front();
            int i = it.first;
            int j = it.second;
            grid[i][j]='0';
            q.pop();
            for(int k = 0; k < 4; k++){
                int ni = i+di[k];
                int nj = j+dj[k];
                if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]=='1'){
                    q.push({ni,nj});
                }
            }
        }
    }
};
