class Solution {
public:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited, int &m, int &n){
        visited[i][j]=1;
        int di[]={1,-1,0,0};
        int dj[]={0,0,1,-1};

        for(int k=0;k<4;k++){
            int new_i=i+di[k];
            int new_j=j+dj[k];

            if(new_i<m && new_i>=0 && new_j<n && new_j>=0 && grid[new_i][new_j]=='1' && visited[new_i][new_j]==0){
                dfs(new_i,new_j,grid,visited,m,n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
       int m = grid.size(), n = grid[0].size();
       vector<vector<bool>> visited(m,vector<bool>(n,0));
       int res=0;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                res++;
                dfs(i,j,grid,visited,m,n);
            }
        }
       }

       return res;
    }
};
